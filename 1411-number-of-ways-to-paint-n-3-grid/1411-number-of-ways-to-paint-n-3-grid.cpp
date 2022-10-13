class Solution {
public:
    int dp[5001][4][4][4],md=1e9+7,N;
    int solve(int i,int c1,int c2,int c3){
        if(i==N)return 1;
        if(dp[i][c1][c2][c3]!=0)return dp[i][c1][c2][c3];
        int res=0;
        for(int a=1;a<=3;a++){
            for(int b=1;b<=3;b++){
                for(int c=1;c<=3;c++){
                    if(a==c1||b==c2||c==c3||a==b||b==c)continue;
                    res+=solve(i+1,a,b,c);
                    res%=md;
                }
            }
        }
        return dp[i][c1][c2][c3]=res;
    }
    int numOfWays(int n) {
        N=n;
        memset(dp,0,sizeof(dp));
        return solve(0,0,0,0);
    }
};