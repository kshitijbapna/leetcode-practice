class Solution {
public:
    int dp[31][1001],m=1e9+7;
    int solve(int i,int n,int k,int curr,int target){
        if(curr>target||i>n)return 0;
        if(i==n&&curr==target)return 1;
        if(dp[i][curr]!=-1)return dp[i][curr];
        long long ans=0;
        for(int ii=1;ii<=k;ii++){
            ans+=solve(i+1,n,k,curr+ii,target);
            ans%=m;
        }
        return dp[i][curr]=ans;
    }
    int numRollsToTarget(int n, int k, int target) {
        memset(dp,-1,sizeof(dp));
        return solve(0,n,k,0,target);
    }
};