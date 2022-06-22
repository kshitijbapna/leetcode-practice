// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int dp[100005][2];
	int solve(int N,int prev){
	    if(N==0)return 1;
	    if(dp[N][prev]!=-1)return dp[N][prev];
	    long long k1=0,k2=0;
	    if(prev!=1)k1=solve(N-1,1);
	    k2=solve(N-1,0);
	   // cout<<N<<" "<<k1<<" "<<k2<<"\n";
	    return dp[N][prev]=(k1+k2)%(int)(1e9+7);
	}
	int TotalWays(int N)
	{
	    memset(dp,-1,sizeof(dp));
	    long long k=solve(N,0);
	    k*=k;
	    k%=(int)(1e9+7);
	   // for(int i=0;i<5;i++)cout<<dp[i]<<" ";
	    return k;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends