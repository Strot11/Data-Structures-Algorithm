class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int shortest = k;
        for(int i=0;i<nums.size();i++){
            if(shortest == nums[i]) shortest+=k;
        }
        return shortest;
    }
};