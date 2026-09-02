class Solution {
public:
    int mod = 1e9+7;
    int power(long long base, long long exp){
        int res = 1;
        while(exp > 0){
            if(exp % 2 == 1) res = (base * res) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }

        return res;
    }
    long long solve(long long w,long long d){
        vector<int> digits;
        while(d > 0){
            digits.push_back(d%10);
            d /=10;
        }
        long long x = 0;
        long long y = 0;
        for(int i = digits.size()-1;i>=0;i--){
            if(w>0){
                x = x*10 + digits[i];
                w--;
            }
            else{
                y = y*10 + digits[i];
            }
        }
        return power(x,y);
    }
    int sumDecoded(vector<long long>& nums) {
        long long sum = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            long long width = nums[i] % 10;
            long long di = floor(nums[i] /10);
            long long val = solve(width,di);
            sum = (sum + val)%mod;
        } 
        return sum;
    }
};