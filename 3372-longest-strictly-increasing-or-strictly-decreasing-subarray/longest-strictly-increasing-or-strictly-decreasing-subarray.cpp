class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int fcnti=INT_MIN;
        int fcntd = INT_MIN;
        int cnti = 1;
        int cntd = 1;
        int n = nums.size();
      
        for(int i=0;i<n;i++){
            if(i+1<n && nums[i]<nums[i+1]){
                cnti++;
            }
            else{
                fcnti = max(fcnti,cnti);
                cnti=1;
            }
             if(i+1<n && nums[n-i-1]<nums[n-i-2]){
                cntd++;
            }
            else{
                fcntd = max(fcntd,cntd);
                cntd=1;
            }
        }
        return max(fcnti,fcntd);
    }
};