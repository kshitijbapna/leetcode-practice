class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,INT_MAX);
        dp[0]=0;
        int curr=0;
        for(int i=0;i<n;i++){
            while(curr+1<=nums[i]+i&&curr+1<n){
                curr++;
                dp[curr]=dp[i]+1;
            }
        }
        return dp[n-1];
    }
};