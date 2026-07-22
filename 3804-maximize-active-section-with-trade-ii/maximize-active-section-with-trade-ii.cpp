void buildSegmentTree(int i,int l,int r,int segment[],int arr[]){
    if(l == r){
        segment[i] = arr[l];
        return;
    }
    int mid = l + (r-l)/2;
    buildSegmentTree(2*i+1,l,mid,segment,arr);
    buildSegmentTree(2*i+2,mid+1,r,segment,arr);
    segment[i] = max(segment[2*i+1],segment[2*i+2]);
}
int* constructSg(int arr[],int n){
    int* segment = new int[4*n];
buildSegmentTree(0,0,n-1,segment,arr);
return segment;
}
int querySegmentTree(int start,int end,int i,int l,int r,int segment[]){
    if(start > r || end < l) return INT_MIN;
    if(start <= l && end>=r) return segment[i];
    int mid = l + (r-l)/2;
    int res1 = querySegmentTree(start,end,2*i+1,l,mid,segment);
    int res2 = querySegmentTree(start,end,2*i+2,mid+1,r,segment);
    return max(res1,res2);
}
int RMQ(int segment[],int n,int a,int b){
    return querySegmentTree(a,b,0,0,n-1,segment);
}
class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.length();
        int activeCount = count(s.begin(),s.end(),'1');
        vector<int> blockStart;
        vector<int> blockEnd;
        int i = 0;
        while(i<n){
            if(s[i] == '0'){
                int start = i;
                while(i<n && s[i]!='1') i++;
                blockStart.push_back(start);
                blockEnd.push_back(i-1);
            }
            else i++;
        }
        //eg 111000111 no 1 between 0s so operation tradeoff can't be done.
        if(blockStart.size() <=1) return vector<int> (queries.size(),activeCount);
        int m = blockStart.size();
        vector<int> blockSize(m,0);
        for(int i=0;i<m;i++){
            blockSize[i] = blockEnd[i] - blockStart[i] + 1;
        }
        //pairSum blockSize[i]+ blockSize[i+1];
        vector<int> pairSum;
        for(int i=0;i<m-1;i++){
            pairSum.push_back(blockSize[i]+blockSize[i+1]);
        }
        int k = pairSum.size();
        int* st = constructSg(pairSum.data(),k); //nothing just hand the first element reference of vector to be used like array required by function. 
        vector<int> result;
        for(auto q:queries){
            int l = q[0];
            int r = q[1];
            //first block in this range
            int low = lower_bound(blockEnd.begin(),blockEnd.end(),l) -  blockEnd.begin();
            int high = upper_bound(blockStart.begin(),blockStart.end(),r) - blockStart.begin() - 1;
          int maxPairSum = 0;
          if(low < high) {
            int firstlen = blockEnd[low] - max(blockStart[low],l) + 1;
            int lastlen = min(blockEnd[high],r) - blockStart[high] + 1;

            if(high - low == 1){
                //exactly two blocks
                maxPairSum = firstlen + lastlen;
            }
            else{
                int pair1 = firstlen + blockSize[low+1];
                int pair2 = lastlen + blockSize[high-1];
                int RMQmiddle = RMQ(st,k,low+1,high-2);
                maxPairSum = max({pair1,pair2,RMQmiddle});
            }
          }
          result.push_back(maxPairSum + activeCount);
        }
    return result;
    }
};