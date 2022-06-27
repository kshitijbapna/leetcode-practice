class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.size(),m=word2.size();
        // if(n==0)return m;
        // if(m==0)return n;
        vector<vector<int>> dp(m+1,vector<int>(n+1));
        for(int i=0;i<=n;i++)dp[0][i]=i;
        for(int j=0;j<=m;j++)dp[j][0]=j;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(word1[j-1]==word2[i-1]){
                    dp[i][j]=dp[i-1][j-1];
                }
                else{
                    dp[i][j]=min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+1;
                }
            }
        }
        return dp[m][n];
    }
};