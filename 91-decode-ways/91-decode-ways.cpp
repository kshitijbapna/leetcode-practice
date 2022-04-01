class Solution {
public:
    int dp[105];
    int fun(string s,int n){
        int a1=0,a2=0;
        if(n<0)return 1;
        if(dp[n]!=-1)return dp[n];
        if(n>=1){
            string b;
            b+=s[n-1];b+=s[n];
            // cout<<b<<"\n";
            if(stoi(b)>=10&&stoi(b)<=26){
                // cout<<b<<"\n";
                a1=fun(s,n-2);
            }
        }
        string b;
        b+=s[n];
        // cout<<b<<"\n";
        if(stoi(b)>=1){
            // cout<<b<<"here\n";
            a2=fun(s,n-1);
        }
        return dp[n]=a1+a2;
    }
    int numDecodings(string s) {
        memset(dp,-1,sizeof(dp));
        if(s[0]=='0')return 0;
        // cout<<"\n\n";
        return fun(s,s.size()-1);
    }
};