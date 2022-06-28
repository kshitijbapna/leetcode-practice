// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int lcs(string &A,string &B,int i,int j,vector<vector<int>> &dp){
        if(i<0||j<0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(A[i]==B[j])return dp[i][j]=1+lcs(A,B,i-1,j-1,dp);
        return dp[i][j]=max({lcs(A,B,i-1,j,dp),lcs(A,B,i,j-1,dp)});
    }
    int longestPalinSubseq(string A) {
        int n=A.size();
        string B=A;
        reverse(B.begin(),B.end());
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return lcs(A,B,n-1,n-1,dp);
    }
};

// { Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends