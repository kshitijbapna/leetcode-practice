// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int ncr[1001][801];
    int nCr(int n, int r){
        //n!/r!(n-r)!
        //ncr-1=r/(n-r+1)*ncr
        int m=(1e9+7);
        for(int i=1;i<1001;i++){
            ncr[i][0]=1;
            ncr[i][1]=i;
            if(i<=800)
            ncr[i][i]=1;
        }
        for(int i=3;i<1001;i++){
            for(int j=1;j<=min(i,800);j++){
                ncr[i][j]=(ncr[i-1][j]+ncr[i-1][j-1])%m;
            }
        }
        // for(int i=0;i<10;i++){
        //     for(int j=0;j<10;j++){
        //         cout<<ncr[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
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