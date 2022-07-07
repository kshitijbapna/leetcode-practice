class Solution {
public:
    bool solve(string &a,string &b,string &c,int n,int m,int sz,vector<vector<int>> &dp){
        if(sz==0)return 1;
        if(dp[n][m]!=-1)return dp[n][m];
        int va=0,vb=0;
        if(n-1>=0&&a[n-1]==c[sz-1])va=solve(a,b,c,n-1,m,sz-1,dp);
        if(m-1>=0&&b[m-1]==c[sz-1])vb=solve(a,b,c,n,m-1,sz-1,dp);
        
        return dp[n][m]=(va|vb);
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.size(),m=s2.size(),k=s3.size();
        if((n+m)!=k)return 0;
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return solve(s1,s2,s3,n,m,k,dp);
    }
};