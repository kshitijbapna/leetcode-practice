// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
#include <bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.

class Solution{
		

	public:
	int solve(int n,vector<int> &wt,vector<int> &co,int W,vector<vector<int>> &dp){
	    if(n<0||W<0)return 1e7;
	    if(W==0){
	        return 0;
	    }
	    if(dp[n][W]!=-1)return dp[n][W];
	    int k1=min(co[n]+solve(n,wt,co,W-wt[n],dp),(int)1e7);
	    int k2=min(solve(n-1,wt,co,W,dp),(int)1e7);
	    return dp[n][W]=min(k1,k2);
	}
	int minimumCost(int cost[], int N, int W) 
	{ 
        vector<int> wt,co;
        for(int i=0;i<N;i++){
            if(cost[i]!=-1){
                wt.push_back(i+1);
                co.push_back(cost[i]);
            }
        }
        vector<vector<int>> dp(co.size(),vector<int>(W+1,-1));
        // for(int i=0;i<co.size();i++){
        //     for(int j=0;j<=W;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        return solve(co.size()-1,wt,co,W,dp);
	} 
};


// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, w;
        cin >> n >> w;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minimumCost(a, n, w) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends