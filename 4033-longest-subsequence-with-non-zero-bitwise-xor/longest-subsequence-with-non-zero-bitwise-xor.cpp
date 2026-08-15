class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int x = 0;
        int j = 0;
        int n = nums.size();
        bool allZeros = true;
        while(j<n){
            x ^= nums[j];
            if(nums[j]!=0) allZeros = false;
            j++;
        }
        if(allZeros) return 0;
        return (x==0) ? n-1 : n;
    }
};