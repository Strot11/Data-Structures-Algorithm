class Solution {
public:
int mod = 1e9+7;
    int maxSum(vector<int>& nums, int k) {
       vector<int> bits(32,0);
       int n = nums.size();
       for(int i=0;i<n;i++){
           for(int b=0;b<32;b++){
            if((nums[i]>>b)&1) bits[b]++;
           }
       }
       long long sum = 0;
       while(k--){
        int num = 0;
         for(int b=0;b<32;b++){
            if(bits[b]>0){
                bits[b]--;
                num = num | (1<<b);
            }
         }
         sum = (sum + (1LL*num*num)%mod)%mod;
       }
       return sum;
    }
};