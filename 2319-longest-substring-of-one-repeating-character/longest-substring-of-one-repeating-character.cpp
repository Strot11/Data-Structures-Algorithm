
class Solution {
public:
  struct Node {
    int pre = 0;
    int suf = 0;
    int maxLen = 0;
    char leftChar = 0;
    char rightChar = 0;
  };
  int n;
  vector<Node> segTree;
Node merge(Node L,Node R,int leftlen,int rightlen){
    Node result; //merged node
    result.leftChar = L.leftChar;
    result.rightChar = R.rightChar;
    result.pre = L.pre;
    if(L.pre == leftlen && L.rightChar==R.leftChar){
        result.pre = L.pre + R.pre;
    }
    result.suf = R.suf;
    if(R.suf== rightlen && L.rightChar == R.leftChar){
        result.suf = R.suf + L.suf;
    }
    result.maxLen = max(L.maxLen,R.maxLen);
    if(L.rightChar == R.leftChar){
        result.maxLen = max(result.maxLen,L.suf+R.pre);
    }
    return result;
}

void buildSegmentTree(int i,int l,int r,string& s){
    if(l == r){
        segTree[i]= {1,1,1,s[l],s[r]};
        return;
    }
    int mid = l+(r-l)/2;
    buildSegmentTree(2*i+1,l,mid,s);
    buildSegmentTree(2*i+2,mid+1,r,s);
    segTree[i] = merge(segTree[2*i+1],segTree[2*i+2],mid-l+1,r-mid);
}

void update(int i,int l,int r,int pos,char ch){
    if(l==r){
         segTree[i]= {1,1,1,ch,ch};
        return;
    }
       int mid = l+(r-l)/2;
       if(pos<= mid){
        update(2*i+1,l,mid,pos,ch);
       }
       else{
        update(2*i+2,mid+1,r,pos,ch);
       }
       segTree[i] = merge(
    segTree[2*i+1],
    segTree[2*i+2],
    mid-l+1,
    r-mid
);
}
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        n= s.length();
        segTree.assign(4*n,Node());
        buildSegmentTree(0,0,n-1,s);

        int k =queryIndices.size();
        vector<int> result(k);
        for(int i=0;i<k;i++){
            int pos = queryIndices[i];
            char ch = queryCharacters[i];
            update(0,0,n-1,pos,ch);

            result[i] = segTree[0].maxLen;
        }
        return result;
    }
};