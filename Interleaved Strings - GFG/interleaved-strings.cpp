// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    bool solve(string &a,string &b,string &c,int n,int m,int sz,vector<vector<int>> &dp){
        if(sz==0)return 1;
        if(dp[n][m]!=-1)return dp[n][m];
        int va=0,vb=0;
        if(n-1>=0&&a[n-1]==c[sz-1])va=solve(a,b,c,n-1,m,sz-1,dp);
        if(m-1>=0&&b[m-1]==c[sz-1])vb=solve(a,b,c,n,m-1,sz-1,dp);
        
        return dp[n][m]=(va|vb);
    }
    bool isInterleave(string A, string B, string C) 
    {
        int n=A.size(),m=B.size(),sz=C.size();
        if(sz!=n+m)return 0;
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return solve(A,B,C,n,m,sz,dp);
    }

};

// { Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		Solution obj;
		cout<<obj.isInterleave(a,b,c)<<endl;
	}
	// your code goes here
	return 0;
}  // } Driver Code Ends