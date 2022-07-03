// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long int dp[1001]={0},m=1e9+7;
    long long int countBT(int h) { 
        if(h==0)return 0;
        else if(h==1)return 1;
        else if(h==2)return 3;
        if(dp[h]!=0)return dp[h];
        return dp[h]=(2ll*countBT(h-1)*countBT(h-2)%m+countBT(h-1)*countBT(h-1)%m)%m;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int h;
        cin >> h;
        Solution ob;
        cout<<ob.countBT(h)<<endl;  
    }
    return 0;
}
  // } Driver Code Ends