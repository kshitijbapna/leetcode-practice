class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return 1;
        vector<int> dp(n,0);
        dp[0]=1;
        int curr_max=0;
        for(int i=0;i<n;i++){
            if(dp[i]==1)
            while(curr_max+1<=nums[i]+i){
                curr_max++;
                dp[curr_max]=1;
                if(curr_max==n-1)return 1;
            }
        }
        return 0;
    }
};