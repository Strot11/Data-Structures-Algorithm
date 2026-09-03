class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int n = nums.size();
        int minOdd = INT_MAX;
        for(int i=0;i<n;i++){
            if(nums[i]&1){
                minOdd = min(minOdd,nums[i]);
            }
        }
        if(minOdd == INT_MAX) return true;
        for(int i=0;i<n;i++){
            if(nums[i]%2 == 0 && nums[i]<=minOdd)  return false;
        }
        return true;
        
    }
};