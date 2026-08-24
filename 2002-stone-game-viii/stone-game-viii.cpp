class Solution {
public:
vector<int> prefix;
int n;
vector<int> dp;
int solve(int x){
    if(x == n-1) return prefix[n-1];
    if(dp[x]!=INT_MIN) return dp[x];
    int take = prefix[x] - solve(x+1);
    int skip = solve(x+1);
    return dp[x] = max(take,skip);
}
    int stoneGameVIII(vector<int>& stones) {
        n = stones.size();
        prefix.assign(n,0);
        dp.resize(n,INT_MIN);
        prefix[0] = stones[0];
        for(int i=1;i<n;i++){
            prefix[i] = stones[i] + prefix[i-1];
        }
        return solve(1);
    }
};