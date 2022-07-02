// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int solve(int k,int n,vector<vector<int>> &dp){
        if(n==0||n==1)return n;
        if(k==1)return n;
        if(dp[k][n]!=-1)return dp[k][n];
        int mn=INT_MAX;
        for(int i=1;i<=n;i++){
            int left=0,right=0;
            if(dp[k-1][i-1]!=-1)left=dp[k-1][i-1];
            else dp[k-1][i-1]=left=solve(k-1,i-1,dp);
            if(dp[k][n-i]!=-1)right=dp[k][n-i];
            else right=dp[k][n-i]=solve(k,n-i,dp);
            int tmp=1+max(left,right);
            mn=min(mn,tmp);
        }
        return dp[k][n]=mn;
    }
    int eggDrop(int k, int n) 
    {
        vector<vector<int>> dp(k+1,vector<int>(n+1,-1));
        return solve(k,n,dp);
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}
  // } Driver Code Ends