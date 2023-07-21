class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        int m=0;
        vector<int> dp(n,1),cnt(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    if(dp[i]<dp[j]+1){
                        dp[i]=dp[j]+1;
                        cnt[i]=cnt[j];
                    }
                    else if(dp[i]==dp[j]+1){
                        cnt[i]+=cnt[j];
                    }
                }
            }
            m=max(dp[i],m);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            // cout<<dp[i]<<" "<<cnt[i]<<"\n";
            if(dp[i]==m)ans+=cnt[i];
        }
        return ans;
    }
};