class Solution {
public:
    int solve(vector<int> &nums1,vector<int> &nums2,int i,int j,vector<vector<int>> &dp){
        if(i<0||j<0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(nums1[i]==nums2[j])return dp[i][j]=1+solve(nums1,nums2,i-1,j-1,dp);
        else return dp[i][j]=max(solve(nums1,nums2,i-1,j,dp),solve(nums1,nums2,i,j-1,dp));
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(nums1,nums2,n-1,m-1,dp);
    }
};