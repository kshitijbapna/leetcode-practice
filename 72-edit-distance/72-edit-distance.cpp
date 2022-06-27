class Solution {
public:
    int solve(string &w1,string &w2,int n,int m,vector<vector<int>> &dp){
        if(n==0)return m;
        if(m==0)return n;
        if(dp[m][n]!=-1)return dp[m][n];
        if(w1[n-1]==w2[m-1]){
            return dp[m][n]=solve(w1,w2,n-1,m-1,dp);
        }
        return dp[m][n]=1+min({solve(w1,w2,n,m-1,dp),solve(w1,w2,n-1,m,dp),solve(w1,w2,n-1,m-1,dp)});
    }
    int minDistance(string word1, string word2) {
        int n=word1.size(),m=word2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return solve(word1,word2,n,m,dp);
    }
    // int minDistance(string word1, string word2) {
    //     int n=word1.size(),m=word2.size();
    //     // if(n==0)return m;
    //     // if(m==0)return n;
    //     vector<vector<int>> dp(m+1,vector<int>(n+1));
    //     for(int i=0;i<=n;i++)dp[0][i]=i;
    //     for(int j=0;j<=m;j++)dp[j][0]=j;
    //     for(int i=1;i<=m;i++){
    //         for(int j=1;j<=n;j++){
    //             if(word1[j-1]==word2[i-1]){
    //                 dp[i][j]=dp[i-1][j-1];
    //             }
    //             else{
    //                 dp[i][j]=min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+1;
    //             }
    //         }
    //     }
    //     return dp[m][n];
    // }
};