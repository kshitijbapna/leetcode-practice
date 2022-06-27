// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int minDeletions(string str, int n);

int main(){
    int t;
    cin >> t;
    while(t--){
        
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << minDeletions(s, n) << endl;

    }
return 0;
}// } Driver Code Ends

int lcs(string &s,string &t,int i,int j,vector<vector<int>> &dp){
    if(i<0||j<0)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    if(s[i]==t[j]){
        return dp[i][j]=1+lcs(s,t,i-1,j-1,dp);
    }
    return dp[i][j]=max(lcs(s,t,i,j-1,dp),lcs(s,t,i-1,j,dp));
}
int minDeletions(string s, int n) { 
    string t=s;
    reverse(t.begin(),t.end());
    vector<vector<int>> dp(s.size(),vector<int>(t.size(),-1));
    return n-lcs(s,t,s.size()-1,t.size()-1,dp);
} 