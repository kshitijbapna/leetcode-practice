class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        
        int n=nums.size();
        vector<vector<int>> dp(2,vector<int>(n,1));
        int ans=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    dp[0][i]=max(1+dp[1][j],dp[0][i]);
                }
                else if(nums[j]>nums[i]){
                    dp[1][i]=max(1+dp[0][j],dp[1][i]);
                }
                ans=max({ans,dp[0][i],dp[1][i]});
            }
        }
        return ans;
    }
};