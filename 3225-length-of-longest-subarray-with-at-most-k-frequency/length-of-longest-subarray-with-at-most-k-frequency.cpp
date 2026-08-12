class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<long long,int> freq;
        int len = 0;
        int n = nums.size();
        int i = 0;
        int j = 0;
        while(j<n){
            if(freq[nums[j]]<k){
                freq[nums[j]]++;
                j++;
            }
            else{
                while(freq[nums[j]] >= k && i<j){
                    freq[nums[i]]--;
                    i++;
                }
            }
            len = max(len,j-i);
        }
        return len;
    }
};