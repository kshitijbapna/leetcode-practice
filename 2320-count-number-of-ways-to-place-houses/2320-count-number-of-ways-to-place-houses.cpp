class Solution {
public:
    long long dp[10005][2][2],m=1e9+7;
    long long solve(int n,int prev1,int prev2){
        if(n<1)return 1;
        if(dp[n][prev1][prev2]!=-1)return dp[n][prev1][prev2];
        long long k=0;
        if(prev1==0&&prev2==0){
            k=solve(n-1,1,0);k%=m;
            k+=solve(n-1,0,0);k%=m;
            k+=solve(n-1,0,1);k%=m;
            k+=solve(n-1,1,1);k%=m;
        }
        else if(prev1==0&&prev2==1){
            k=solve(n-1,1,0);k%=m;
            k+=solve(n-1,0,0);k%=m;
        }
        else if(prev1==1&&prev2==0){
            k=solve(n-1,0,1);k%=m;
            k+=solve(n-1,0,0);k%=m;
        }
        else if(prev1==1&&prev2==1){
            k=solve(n-1,0,0);
        }
        k%=m;
        return dp[n][prev1][prev2]=k;
    }
    int countHousePlacements(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(n,0,0);
    }
};