//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int dp[100005]={0},md=1e8;
    int fillingBucket(int N) {
        if(N<=2)return N;
        if(dp[N]!=0)return dp[N];
        return dp[N]=(fillingBucket(N-1)+fillingBucket(N-2))%md;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.fillingBucket(N) << endl;
    }
    return 0;
}
// } Driver Code Ends