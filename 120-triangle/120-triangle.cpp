class Solution {
public:
    int dp[205][205];
    int fun(int i,vector<vector<int>>& tr,int n){
        if(n<0||i<0)return 0;
        if(dp[i][n]!=-1e9)return dp[i][n];
        if(i==0){
            return dp[i][n]=tr[n][i]+fun(i,tr,n-1);
        }
        if(i==tr[n].size()){
            return dp[i][n]=tr[n][i-1]+fun(i-1,tr,n-1);
        }
        return dp[i][n]=tr[n][i]+min(fun(i-1,tr,n-1),fun(i,tr,n-1));
    }
    int minimumTotal(vector<vector<int>>& tr) {
        for(int i=0;i<205;i++)for(int j=0;j<205;j++)dp[i][j]=-1e9;
        int n=tr.size(),ans=INT_MAX;
        for(int i=0;i<tr[n-1].size();i++){
            ans=min(ans,fun(i,tr,n-1));
        }
        return ans;
    }
};