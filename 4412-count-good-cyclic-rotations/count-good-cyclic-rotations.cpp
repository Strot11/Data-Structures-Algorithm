class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        long long pre = 0;
        long long suff = 0;
        int n = nums.size();
        long long ans = 0;
        for(int i=0;i<n/2;i++){
            pre += nums[i];
            suff += nums[n-i-1];
        }
        if(pre > suff) ans++;
        for(int k=0;k<n-1;k++){
           pre  = pre  - nums[k] + nums[(k+n/2)%n];
           suff = suff - nums[(k+n/2)%n] + nums[k];
            if(pre > suff) ans++;
        }
        return ans;
    }
};