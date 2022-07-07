class Solution {
public:
    bool solve(string &s1,string &s2,string &s3,int i,int j,int k,vector<vector<int>> &dp){
        if(k<0)return 1;
        if(i>=0&&j>=0&&dp[i][j]!=-1)return dp[i][j];
        int k1=0,k2=0;
        if(i>=0&&s1[i]==s3[k])k1=solve(s1,s2,s3,i-1,j,k-1,dp);
        if(j>=0&&s2[j]==s3[k])k2=solve(s1,s2,s3,i,j-1,k-1,dp);
        if(i>=0&&j>=0)return dp[i][j]=(k1||k2);
        
        return (k1||k2);
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.size(),m=s2.size(),k=s3.size();
        if((n+m)!=k)return 0;
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(s1,s2,s3,n-1,m-1,k-1,dp);
    }
};