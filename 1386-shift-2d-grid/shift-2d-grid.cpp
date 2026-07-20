class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();  
        int round = m*n;
        k = k%round;
        if(k == 0) return grid;
        vector<vector<int>> ans(m,vector<int>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int r = (i + (j+k)/n) % m;
                int c = (j+k) % n;
                ans[r][c] = grid[i][j];
            }
        }
        return ans;
    }
};