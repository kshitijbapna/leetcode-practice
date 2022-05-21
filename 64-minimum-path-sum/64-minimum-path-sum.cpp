class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size(),i,j;
        for(i=1;i<m;i++)grid[0][i]+=grid[0][i-1];
        for(j=1;j<n;j++)grid[j][0]+=grid[j-1][0];
        for(i=1;i<n;i++)for(j=1;j<m;j++)grid[i][j]+=min(grid[i-1][j],grid[i][j-1]);
        return grid[n-1][m-1];
    }
};