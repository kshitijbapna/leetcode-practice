// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int m=1003;
    int dp[201][201][2];
    int solve(string &s,int i,int j,bool isT){
        if(i>j)return 0;
        if(dp[i][j][isT]!=-1)return dp[i][j][isT];
        if(i==j){
            if(isT==1)return s[i]=='T';
            if(isT==0)return s[i]=='F';
        }
        int ways=0;
        for(int k=i+1;k<j;k+=2){
            int lt=solve(s,i,k-1,1);
            int lf=solve(s,i,k-1,0);
            int rt=solve(s,k+1,j,1);
            int rf=solve(s,k+1,j,0);
            if(s[k]=='|'){
                if(isT){
                    ways+=lt*rt+lt*rf+lf*rt;
                }
                else{
                    ways+=lf*rf;
                }
            }
            else if(s[k]=='&'){
                if(isT){
                    ways+=lt*rt;
                }
                else{
                    ways+=lf*rf+lt*rf+lf*rt;
                }
            }
            else if(s[k]=='^'){
                if(isT){
                    ways+=lt*rf+lf*rt;
                }
                else{
                    ways+=lt*rt+lf*rf;
                }
            }
        }
        return dp[i][j][isT]=ways%1003;
    }
    int countWays(int N, string S){
        memset(dp,-1,sizeof(dp));
        return solve(S,0,N-1,1);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends