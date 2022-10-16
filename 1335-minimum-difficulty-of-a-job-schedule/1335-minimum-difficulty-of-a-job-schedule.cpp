class Solution {
public:
    int solve(vector<int> &jD,int d,int i,vector<vector<int>> &dp){
        int n=jD.size();
        
        if(i==n&&d==0)return 0;
        if(i==n||d==0||n-i<d)return INT_MAX;       
        if(dp[i][d]!=INT_MAX)return dp[i][d];
        long long ans=INT_MAX,k=INT_MIN;
        for(int j=i;j<n;j++){
            k=max(k,1ll*jD[j]);
            ans=min(ans,k+solve(jD,d-1,j+1,dp));
        }
        return dp[i][d]=ans;
    }
    int minDifficulty(vector<int>& jD, int d) {
        int n=jD.size();
        vector<vector<int>> dp(n+1,vector<int>(d+1,INT_MAX));
        int k=solve(jD,d,0,dp);
        return k==INT_MAX?-1:k;
    }
};