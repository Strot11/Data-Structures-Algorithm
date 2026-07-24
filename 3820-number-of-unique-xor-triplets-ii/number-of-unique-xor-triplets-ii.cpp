class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
         unordered_set<int> st2;
        vector<int> temp;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
               st.insert(nums[j]^nums[i]);
            }
        }
        for(int i=0;i<n;i++){
            for(auto &element:st){
                st2.insert(element^nums[i]);
            }
        }
         return st2.size();
    }
};