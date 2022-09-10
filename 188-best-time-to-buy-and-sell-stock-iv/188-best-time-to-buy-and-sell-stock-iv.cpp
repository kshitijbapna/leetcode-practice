class Solution {
public:
    int solve(int n,int k,vector<int> &prices,vector<vector<int>> &dp){
        if(n==1||k==0)return 0;
        else if(n==2&&k>0)return max(0,prices[1]-prices[0]);
        if(dp[n][k]!=-1)return dp[n][k];
        int ans=0,mx_val=0;
        for(int i=n;i>=1;i--){
            int l_ans=solve(i-1,k-1,prices,dp);
            ans=max(ans,l_ans+max(0,mx_val-prices[i-1]));
            mx_val=max(mx_val,prices[i-1]);
        }
        return dp[n][k]=ans;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
        return solve(n,k,prices,dp);
    }
};