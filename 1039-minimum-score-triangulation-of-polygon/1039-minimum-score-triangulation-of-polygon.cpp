class Solution {
public:
    int solve(vector<int> &arr,int i,int j,vector<vector<int>> &dp){
        if(i>=j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int mn=INT_MAX;
        for(int k=i;k<j;k++){
            int tmp=solve(arr,i,k,dp)+solve(arr,k+1,j,dp)+arr[i-1]*arr[k]*arr[j];
            mn=min(mn,tmp);
        }
        return dp[i][j]=mn;
    }
    int minScoreTriangulation(vector<int>& values) {
        int n=values.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(values,1,n-1,dp);
    }
};