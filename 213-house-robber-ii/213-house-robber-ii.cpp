class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        int dp1[n],dp2[n];
        memset(dp1,0,sizeof(dp1)); memset(dp2,0,sizeof(dp2));
        dp1[0]=nums[0];dp2[0]=0;
        dp1[1]=dp2[1]=nums[1];
        for(int i=2;i<n-1;i++){
            dp1[i]=dp1[i-1];
            for(int j=0;j<i-1;j++)dp1[i]=max(dp1[i],dp1[j]+nums[i]);
        }
        for(int i=2;i<n;i++){
            dp2[i]=dp2[i-1];
            for(int j=0;j<i-1;j++)dp2[i]=max(dp2[i],dp2[j]+nums[i]);
        }
        return max({*max_element(dp1,dp1+n),*max_element(dp2,dp2+n)});
    }
};