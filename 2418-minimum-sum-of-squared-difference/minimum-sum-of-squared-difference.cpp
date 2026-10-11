class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long ans = 0;
        long long k = k1+k2;
       vector<long long> AC(1e5+1,0);
        for(int i=0;i<n;i++){
            long long num = abs(nums1[i] - nums2[i]);
            AC[num]++; 
        }
        for(int i=1e5;i>0;i--){
            if(k == 0) break;
            if(AC[i]!=0){
                long long op = min(AC[i],k);
                AC[i] -= op;
                AC[i-1] += op;
                k-=op;
            }
        }
        for(int i=1;i<1e5+1;i++){
           if(AC[i]) ans += (AC[i]*i*i);
        }
        return ans;
    }
};