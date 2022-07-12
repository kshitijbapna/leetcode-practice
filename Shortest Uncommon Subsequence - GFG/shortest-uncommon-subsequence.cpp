// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int shortestUnSub(string S, string T) {
        int n=S.size(),m=T.size(),mx=1001;
        int dp[n+1][m+1];
        for(int i=0;i<=n;i++)dp[i][0]=1;
        for(int i=0;i<=m;i++)dp[0][i]=mx;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int k=j;
                for(;k>=0;k--){
                    if(S[i]==T[k])break;
                }
                if(k<0)dp[i+1][j+1]=1;
                else dp[i+1][j+1]=min(dp[i][j+1],dp[i][k]+1);
            }
        }
        return dp[n][m]>=mx?-1:dp[n][m];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S,T;
        cin>>S>>T;

        Solution ob;
        cout << ob.shortestUnSub(S,T) << endl;
    }
    return 0;
}  // } Driver Code Ends