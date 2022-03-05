class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        int a[20010],n=20010;
        memset(a,0,sizeof(a));
        for(int i=0;i<nums.size();i++)a[nums[i]]++;
        for(int i=0;i<10005;i++){
            a[i]=i*a[i];
        }
        int dp[10005];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<10005;i++){
            if(i>=2)dp[i]=max(dp[i-1],dp[i-2]+a[i]);
            else if(i>=1)dp[i]=(dp[i-1],a[i]);
        }
        return *max_element(dp,dp+10005);
    }
};