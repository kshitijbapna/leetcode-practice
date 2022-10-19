class Solution {
public:
    bool solve(string &s,int i,int j,vector<vector<int>> &dp){
        int n=s.size();
        if(i>j)return 1;
        if(dp[i][j]!=-1)return dp[i][j];
        int len=j-i+1;
        if(s[i]!=s[j])return dp[i][j]=0;
        return dp[i][j]=solve(s,i+1,j-1,dp);
    }
    bool checkPartitioning(string s) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int> (n,-1));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dp[i][j]==-1)
                solve(s,i,j,dp);
            }
        }
        for(int p=0;p<n;p++){
            for(int s=p+2;s<n;s++){
                if(dp[0][p]==1&&dp[p+1][s-1]==1&&dp[s][n-1]==1)return 1;
            }
        }
        return 0;
    }
};