class Solution {
public:
    int dp[101][10001];
    int rec(vector<int>& pf,int n,int j){
        if(n<0)return 1e7;
        if(n==0)return 0;
        if(j<0)return 1e7;
        if(dp[j][n]!=0)return dp[j][n];
        return dp[j][n]=min(1+rec(pf,n-pf[j],j),rec(pf,n,j-1));
    }
    int numSquares(int n) {
        vector<int> pf;
        memset(dp,0,sizeof(dp));
        for(int i=1;i<101;i++){
            pf.push_back(i*i);
        }
        return rec(pf,n,pf.size()-1);
    }
};