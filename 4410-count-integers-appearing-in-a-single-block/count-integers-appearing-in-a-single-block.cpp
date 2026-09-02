class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
       unordered_map<int,vector<int>> mp;
       int n = nums.size();
       for(int i=0;i<n;i++){
        mp[nums[i]].push_back(i);
       }
       int count = 0;
       for(auto &[key,val]:mp){
        bool f = false;
        for(int i=0;i<val.size()-1;i++){
            if(val[i+1] != val[i] + 1) {
               f = true;
               break;
            }
        }
        if(!f) count++;
       }
       return count;
    }
};