// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int ncr[1001][1001];
    int nCr(int n, int r){
        int m=(1e9+7);
        for(int i=1;i<1001;i++){
            ncr[i][0]=1;ncr[i][1]=i;ncr[i][i]=1;
        }
        for(int i=3;i<1001;i++){
            for(int j=1;j<=i;j++){
                ncr[i][j]=(ncr[i-1][j]+ncr[i-1][j-1])%m;
                if(i==n&&j==r)return ncr[n][r];
            }
        }
        return ncr[n][r];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}  // } Driver Code Ends