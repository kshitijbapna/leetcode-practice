class Solution {
public:
    int solve(vector<int>& coins,int amt,int i,vector<vector<int>> &dp){
        if(i<0||amt<0)return 1e5;
        if(amt==0)return 0;
        if(dp[i][amt]!=-1)return dp[i][amt];
        int k1=0,k2=0;
        k1=1+solve(coins,amt-coins[i],i,dp);
        k2=solve(coins,amt,i-1,dp);
        return dp[i][amt]=min(k1,k2);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        int ans=solve(coins,amount,coins.size()-1,dp);
        if(ans==1e5)return -1;
        return ans;
    }
};