class Solution {
public:
    int moves[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
    int dp[205][205];
    int solve(vector<vector<int>>& mat,int i,int j){
        int n=mat.size(),m=mat[0].size(),MAX=1;
        if(i<0||j<0||i>=n||j>=m)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        for(int ii=0;ii<4;ii++){
            int x=i+moves[ii][0],y=j+moves[ii][1];
            if(x>=0&&y>=0&&x<n&&y<m&&mat[x][y]>mat[i][j])MAX=max(MAX,1+solve(mat,x,y));
        }
        return dp[i][j]=MAX;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ans=0;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                ans=max(ans,solve(matrix,i,j));
            }
        }
        return ans;
    }
};