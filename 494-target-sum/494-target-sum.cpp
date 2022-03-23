class Solution {
public:
    int isSub(vector<int> v,int x){
        int dp[v.size()+1][x+1];
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for(int i=0;i<=v.size();i++){
            for(int j=0;j<=x;j++){
                
                if(i==0)dp[i][j]=0;
                if(j==0)dp[i][j]=1;
                // cout<<dp[i][j]<<" ";
            }
            // cout<<"\n";
        }
        for(int i=1;i<=v.size();i++){
            for(int j=0;j<=x;j++){
                if(v[i-1]>j){
                    dp[i][j]=dp[i-1][j];
                }
                else{
                    dp[i][j]=dp[i-1][j-v[i-1]]+dp[i-1][j];
                }
            }
        }
        return dp[v.size()][x];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        long long int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if((target+sum)%2!=0)return 0;
        int x=(target+sum)/2;
        if(abs(target)>sum)return 0;
        sort(nums.rbegin(),nums.rend());
        return isSub(nums,x);
    }
};