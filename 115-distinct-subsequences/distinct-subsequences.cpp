class Solution {
public:
vector<vector<long long>> dp;
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        dp.assign(n+1,vector<long long>(m+1,0));
        for(int i=0;i<=n;i++){
            dp[i][m] = 1;
        }
       for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
    long long take = 0;
    long long nottake = 0;
    if(s[i] == t[j]){
        take = dp[i+1][j+1];
    }
    nottake = dp[i+1][j];
                if (take+nottake > INT_MAX) {
                    dp[i][j] = INT_MAX;
                    continue;
                }

    dp[i][j] = take + nottake;
        }
       }
       return dp[0][0];
    }
};