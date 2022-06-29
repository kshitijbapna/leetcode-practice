// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int m=1003;
    int solve(string &s,int i,int j,bool isT,vector<vector<vector<int>>> &dp){
        if(i>j)return 0;
        if(i==j){
            if(isT==1)return s[i]=='T';
            if(isT==0)return s[i]=='F';
        }
        if(dp[i][j][isT]!=-1)return dp[i][j][isT];
        int ways=0;
        for(int k=i+1;k<j;k+=2){
            int lt=solve(s,i,k-1,1,dp);
            int lf=solve(s,i,k-1,0,dp);
            int rt=solve(s,k+1,j,1,dp);
            int rf=solve(s,k+1,j,0,dp);
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
            else{
                if(isT){
                    ways+=lt*rf+lf*rt;
                }
                else{
                    ways+=lt*rt+lf*rf;
                }
            }
        }
        return dp[i][j][isT]=ways%m;
    }
    int countWays(int N, string S){
        vector<vector<vector<int>>> dp(N,vector<vector<int>>(N,vector<int>(2,-1)));
        return solve(S,0,N-1,1,dp);
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