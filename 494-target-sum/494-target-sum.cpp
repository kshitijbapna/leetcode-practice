class Solution {
public:
    int dp[21][1001];
    int findTargetSumWays(vector<int>& v, int target) {
        int n=v.size(),sum=0;
        for(int i=0;i<n;i++)sum+=v[i];
        int ans=0;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=sum;j++){
                if(i==0)dp[i][j]=0;
                if(j==0)dp[i][j]=1;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=0;j<=sum;j++){
                if(v[i-1]>j){
                    dp[i][j]=dp[i-1][j];
                }
                else{
                    dp[i][j]=dp[i-1][j-v[i-1]]+dp[i-1][j];
                }
            }
        }
        if((target+sum)%2!=0)return 0;
        int x=(target+sum)/2;
        if(abs(target)>sum)return 0;
        return dp[n][x];
    }
};