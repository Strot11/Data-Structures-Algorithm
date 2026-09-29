class Solution {
public:
  vector<vector<vector<int>>> dp;
bool dfs(int x,int y,vector<vector<char>>& grid,int balance){
    if(x > grid.size()-1 || y > grid[0].size()-1) return false;
    if(grid[x][y] == '(') balance++;
    else balance--;
    if(balance < 0) return false;
     if(dp[x][y][balance]!=-1) return dp[x][y][balance];
    if(x == grid.size()-1 && y == grid[0].size()-1) return (balance==0);
    bool right = dfs(x+1,y,grid,balance);
    bool down = dfs(x,y+1,grid,balance);
    return dp[x][y][balance] = (right | down);
}
    bool hasValidPath(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int k = m+n;
        dp.assign(n,vector<vector<int>>(m,vector<int>(k,-1)));
        return dfs(0,0,grid,0);
    }
};