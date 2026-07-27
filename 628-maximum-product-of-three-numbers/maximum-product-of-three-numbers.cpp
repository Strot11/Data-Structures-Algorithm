class Solution {
public:
    int maximumProduct(vector<int>& nums) {
         int maxi1=INT_MIN;
        int maxi2=INT_MIN;
        int maxi3=INT_MIN;

        int min1=INT_MAX;
        int min2=INT_MAX;

        for(int x:nums){
            if(x>=maxi1){
                maxi3=maxi2;
                maxi2=maxi1;
                maxi1=x;
            }else if(x>=maxi2){
                maxi3=maxi2;
                maxi2=x;

            }else if(x>=maxi3){
                      maxi3=x;
            }
            if(x<=min1){
                min2=min1;
                min1=x;

            }else if(x<min2 ){
                min2=x;
            }
        }
        return max(maxi1*maxi2*maxi3,min1*min2*maxi1);
    }
};