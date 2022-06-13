// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
	    int solve(int i,int j,string &s,string &t,vector<vector<int>>& dp){
	        if(i<0||j<0)return 0;
	        if(dp[i][j]!=-1)return dp[i][j];
	        if(i!=j&&s[i]==t[j])return dp[i][j]=1+solve(i-1,j-1,s,t,dp);
	        int a=solve(i-1,j,s,t,dp),b=solve(i,j-1,s,t,dp);
	        return dp[i][j]=max(a,b);
	    }
		int LongestRepeatingSubsequence(string str){
            int n=str.size();
            vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
            return solve(n-1,n-1,str,str,dp);
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends