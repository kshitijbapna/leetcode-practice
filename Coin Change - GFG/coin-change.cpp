// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    long long int dp[1001][1001];
    long long int help(int s[],int i,int n){
        if(i<0)return 0;
        if(n==0)return 1;
        if(n<0)return 0;
        if(dp[i][n]!=-1)return dp[i][n];
        long long int k1=0,k2=0;
        k1=help(s,i-1,n);       //dont take
        k2=help(s,i,n-s[i]);        //take
        return dp[i][n]=k1+k2;
    }
    long long int count(int S[], int m, int n) {
        memset(dp,-1,sizeof(dp));
        return help(S,m-1,n);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int arr[m];
        for (int i = 0; i < m; i++) cin >> arr[i];
        Solution ob;
        cout << ob.count(arr, m, n) << endl;
    }

    return 0;
}  // } Driver Code Ends