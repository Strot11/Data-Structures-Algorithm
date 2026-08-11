class Solution {
public:
    int missingInteger(vector<int>& nums) {
    int ans = nums[0];
       int sum = nums[0];
       int n = nums.size();
       if(n == 1) return nums[0]+1;
       for(int i=1;i<n;i++){
        if(nums[i] == nums[i-1]+1){
            sum+=nums[i];
              ans = max(ans,sum);
        }
        else break;
       } 
         ans = max(ans,sum);
       for(int i=ans;i<=INT_MAX;i++){
        bool found = false;
            for(int j=0;j<n;j++){
                if(nums[j]==i) {
                    found= true;
                    break;
                }
            }
            if(!found) return i;
       }
       return -1;
    }
};