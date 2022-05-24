class Solution {
public:
    int dp[100005][2];
    int solve(vector<int>& nums1,vector<int>& nums2,int in,int prev1,int prev2,int sw){
        int n=nums1.size();
        if(in==n)return 0;
        if(dp[in][sw]!=-1)return dp[in][sw];
        int res=INT_MAX;
        if(nums1[in]>prev1&&nums2[in]>prev2){
            res=solve(nums1,nums2,in+1,nums1[in],nums2[in],0);
        }
        if(nums2[in]>prev1&&nums1[in]>prev2){
            res=min(res,solve(nums1,nums2,in+1,nums2[in],nums1[in],1)+1);
        }
        return dp[in][sw]=res;
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        memset(dp,-1,sizeof(dp));
        
        return solve(nums1,nums2,0,-1,-1,0);
    }
};