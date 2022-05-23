class Solution {
public:
    int dp[101][101][601];
    int solve(vector<string>& s, int m, int n,int k){
        if(k<0)return 0;
        if(dp[m][n][k]!=-1)return dp[m][n][k];
        int on=0,ze=0;
        for(int i=0;i<s[k].size();i++){
            if(s[k][i]=='1')on++;
            else ze++;
        }
        if(m>=ze&&n>=on)return dp[m][n][k]=max(1+solve(s,m-ze,n-on,k-1),solve(s,m,n,k-1));
        else return dp[m][n][k]=solve(s,m,n,k-1);
        return -1;
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp,-1,sizeof(dp));
        return solve(strs,m,n,strs.size()-1);
    }
};