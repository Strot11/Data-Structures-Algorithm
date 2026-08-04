class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int mini = *min_element(nums.begin(),nums.end());
        vector<int> ans;
        int j = 0;
        for(int i=0;i<n;){
           if((mini+j)!=nums[i]) {
            ans.push_back(mini+j);
            j++;
            continue;
           }
           i++;
           j++;
        }
        return ans;
    }
};