// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    // int solve(int n,int arr[],int sum,vector<vector<int>> &dp){
    //     if(sum==0)return 1;
    //     if(sum<0||n<0)return 0;
    //     if(dp[n][sum]!=-1)return dp[n][sum];
    //     return dp[n][sum]=(solve(n-1,arr,sum,dp)||solve(n-1,arr,sum-arr[n],dp));
    // }
    int equalPartition(int N, int arr[])
    {
        int sum=0;
        for(int i=0;i<N;i++)sum+=arr[i];
        if(sum%2)return 0;
        sum/=2;
        vector<vector<int>> dp(N+1,vector<int>(sum+1,0));
        for(int i=0;i<=sum;i++)dp[0][i]=0;
        for(int i=0;i<=N;i++)dp[i][0]=1;
        for(int i=1;i<=N;i++){
            for(int j=1;j<=sum;j++){
                if(j-arr[i-1]>=0){
                    dp[i][j]=dp[i-1][j]||dp[i-1][j-arr[i-1]];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[N][sum];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends