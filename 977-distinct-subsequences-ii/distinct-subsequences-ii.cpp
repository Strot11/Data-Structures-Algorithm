class Solution {
public:
int M = 1e9+7;
int dp[2001];
vector<int> prev;
    int distinctSubseqII(string s) {
        int n= s.length();
        memset(dp,-1,sizeof(dp));
        prev.assign(n+1,0);
        vector<int> lastseen(26,0);
        for(int i=1;i<=n;i++){
            int idx = s[i-1]-'a';
            prev[i] = lastseen[idx];
            lastseen[idx] = i;
        }
        dp[0] = 1; 
        for(int i=1;i<=n;i++){
            int total = (2*(dp[i-1])%M)%M;
            int duplicates = (prev[i]!=0) ? dp[prev[i] - 1] : 0;
            dp[i] = (total - duplicates + M)%M;
        }
        return (dp[n]-1 + M)%M;
    }
};