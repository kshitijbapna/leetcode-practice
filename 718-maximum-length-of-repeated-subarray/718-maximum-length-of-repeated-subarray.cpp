class Solution {
public:
    vector<vector<int>> dp;
    int ans=0;
    int solve(vector<int> &A,vector<int> &B,int i,int j,int n,int m){
        if(i>=n||j>=m)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        solve(A,B,i+1,j,n,m);solve(A,B,i,j+1,n,m);
        if(A[i]==B[j])dp[i][j]=solve(A,B,i+1,j+1,n,m)+1;
        else dp[i][j]=0;
        ans=max(ans,dp[i][j]);
        return dp[i][j];
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        dp.resize(n,vector<int>(m,-1));
        solve(nums1,nums2,0,0,n,m);
        return ans;
    }
};