class Solution {
public:
    int dp[205][10005];
    bool canPartition(vector<int>& nums) {
        int n=nums.size(),sum=0;
        for(int i=0;i<n;i++)sum+=nums[i];
        if(sum%2==0){
            sum/=2;
            for(int i=1;i<=n;i++){
                for(int j=0;j<=sum;j++){
                    if(j==0){
                        dp[i][j]=1;
                        continue;
                    }
                    if(nums[i-1]<=j){
                        dp[i][j]=dp[i-1][j]|dp[i-1][j-nums[i-1]];
                    }
                    else{
                        dp[i][j]=dp[i-1][j];
                    }
                }
            }
            return dp[n][sum];
        }
        return 0;
    }
};