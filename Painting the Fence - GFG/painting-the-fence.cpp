// { Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    vector<long long> dp;
    long long solve(int post,int k,vector<vector<int>>& dp,int prevC,int prev){
        int n=dp.size()-1;
        if(post>n)return 1;
        if(dp[post][prev]!=-1)return dp[post][prev];
        long long ans=0;
        for(int c=0;c<k;c++){
            if(prev==2&&prevC==c)continue;
            if(prevC==c)ans+=solve(post+1,k,dp,c,prev+1);
            else ans+=solve(post+1,k,dp,c,1);
            ans%=(int)(1e9+7);
        }
        return dp[post][prev]=ans;
    }
    long long countWays(int n, int k){
        vector<vector<int>> dp(n+1,vector<int>(3,-1));
        return solve(1,k,dp,-1,0);
    }
};

// { Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}  // } Driver Code Ends