class Solution {
public:
    int latest_non_ov_opt(vector<vector<int>> &v,int i){
        int l=0,r=i-1;
        while(l<=r){
            int m=(l+r)/2;
            if(v[m][0]<=v[i][1]){
                if(v[m+1][0]<=v[i][1])
                    l=m+1;
                else 
                    return m;
            }
            else r=m-1;
        }
        return -1;
    }
    int solve(vector<vector<int>> &v,int n,vector<int> &dp){
        if(n==1)return v[n-1][2];
        if(dp[n]!=-1)return dp[n];
        int ex=solve(v,n-1,dp);
        int in=v[n-1][2];
        int i=latest_non_ov_opt(v,n-1);
        if(i!=-1)
            in+=solve(v,i+1,dp);
        return dp[n]=max(in,ex);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=startTime.size();
        vector<vector<int>> v(n,vector<int>(3));
        for(int i=0;i<n;i++){
            v[i]={endTime[i],startTime[i],profit[i]};
        }
        sort(v.begin(),v.end());
        vector<int> dp(n+1,-1);
        return solve(v,n,dp);
    }
};