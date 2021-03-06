// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    // int help(int i,vector<int>& arr,vector<int>& dp){
    //     if(i<0)return 0;
    //     int k1=0,k2=0;
    //     if(dp[i]!=-1)return dp[i];
    //     k1=arr[i]+help(i-2,arr,dp);
    //     k2=help(i-1,arr,dp);
    //     return dp[i]=max(k1,k2);
    // }
    int FindMaxSum(int arr[], int n)
    {
        vector<int> dp(n,-1);
        dp[0]=arr[0];
        dp[1]=max(arr[1],arr[0]);
        for(int i=2;i<n;i++){
            dp[i]=max(dp[i-2]+arr[i],dp[i-1]);
        }
        return dp[n-1];
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
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}
  // } Driver Code Ends