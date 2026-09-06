class Solution {
public:
string temp;
vector<vector<int>> dp;
int solve(int i,int j,string &s, string &t){
    if(i == s.length() || j == t.length()){
        return (temp == t);
    }
    if(dp[i][j]!=-1) return dp[i][j];
    int take = 0;
    int nottake = 0;
    if(s[i] == t[j]){
        temp.push_back(s[i]);
        take = solve(i+1,j+1,s,t);
        temp.pop_back();
    }
    nottake = solve(i+1,j,s,t);
    return dp[i][j] = take + nottake;
}
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        dp.assign(n,vector<int>(m,-1));
        return solve(0,0,s,t);
    }
};