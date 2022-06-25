class Solution {
public:
    string shortestCommonSupersequence(string X, string Y) {
        int m=X.size(),n=Y.size(),dp[m+1][n+1];
        for(int i=0;i<=m;i++)dp[i][0]=0;
        for(int j=0;j<=n;j++)dp[0][j]=0;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(X[i-1]==Y[j-1])dp[i][j]=dp[i-1][j-1]+1;
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        int i=m,j=n;
        string lcs;
        while(i>0&&j>0){
            if(X[i-1]==Y[j-1]){
                lcs+=X[i-1];
                i--;
                j--;
            }
            else{
                if(dp[i-1][j]>dp[i][j-1]){
                    i--;
                }
                else{
                    j--;
                }
            }
        }
        reverse(lcs.begin(),lcs.end());
        int curr=0;
        i=0;j=0;
        string ans;
        while(curr<lcs.size()&&i<m&&j<n){
            if(lcs[curr]==X[i]&&X[i]==Y[j]){
                ans+=lcs[curr++];
                i++;
                j++;
            }
            else if(lcs[curr]==X[i]&&X[i]!=Y[j]){
                ans+=Y[j++];
            }
            else if(lcs[curr]==Y[j]&&X[i]!=Y[j]){
                ans+=X[i++];
            }
            else{
                ans+=Y[j++];
                ans+=X[i++];
            }
        }
        while(i<m)ans+=X[i++];
        while(j<n)ans+=Y[j++];
        return ans;
    }
};