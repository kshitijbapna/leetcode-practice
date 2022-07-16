class Solution {
public:
    int dp[51][51][51];
    int mod=1e9+7;
    int solve(int m,int n,int mx,int i,int j){
        if(mx<0)return 0;
        if(i<0||j<0||i>=m||j>=n)return 1;
        if(dp[i][j][mx]!=-1)return dp[i][j][mx];
        return dp[i][j][mx]=((long long)solve(m,n,mx-1,i+1,j)+solve(m,n,mx-1,i-1,j)+solve(m,n,mx-1,i,j+1)+solve(m,n,mx-1,i,j-1))%mod;
    }
    int findPaths(int m, int n, int mx, int startRow, int startColumn) {
        memset(dp,-1,sizeof(dp));
        return solve(m,n,mx,startRow,startColumn);
    }
};