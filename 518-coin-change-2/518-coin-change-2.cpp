class Solution {
public:
    int dp[300+1][5000+1];
    int change(int amt, vector<int>& coins) {
        int n=coins.size();
        for(int i=1;i<=n;i++){
            for(int j=0;j<=amt;j++){
                if(j==0){
                    dp[i][j]=1;
                    continue;
                }
                if(coins[i-1]<=j)dp[i][j]=dp[i-1][j]+dp[i][j-coins[i-1]];
                else dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][amt];
    }
};