// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
   int dp[1001][1001];
    int solve(int n,int W,int val[],int wt[]){
        if(n<0||W<0)return 0;
        if(dp[n][W]!=-1)return dp[n][W];
        int k1=0,k2=0;
        if(wt[n]<=W)k1=val[n]+solve(n,W-wt[n],val,wt);
        k2=solve(n-1,W,val,wt);
        return dp[n][W]=max(k1,k2);
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        // vector<vector<int>> dp(N,vector<int>(W,-1));
        memset(dp,-1,sizeof(dp));
        return solve(N-1,W,val,wt);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}  // } Driver Code Ends