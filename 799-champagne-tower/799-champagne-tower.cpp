class Solution {
public:
    double champagneTower(int poured, int row, int glass) {
        double dp[105][105];
        memset(dp,0,sizeof(dp));
        dp[0][0]=poured;
        for (int i=0;i<101;i++) {
            for (int j=0;j<=i;j++) {
                if (dp[i][j]>1) {
                    dp[i+1][j]+=(dp[i][j]-1)/2;
                    dp[i+1][j+1]+=(dp[i][j]-1)/2;
                    dp[i][j]=1;
                }
            }
        }
        return dp[row][glass];
    }
};