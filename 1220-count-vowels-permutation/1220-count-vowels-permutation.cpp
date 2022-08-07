class Solution {
public:
    int m=1e9+7,n;
    long long dp[128][20005];
    long long solve(char prev,int i){
        if(i==n)return 1;
        
        int x=prev;
        if(dp[x][i]!=-1)return dp[x][i];
        int ans=0;
        if(prev=='#'){
            if(i==n-1){
                return dp[x][i]=5;
            }
            return dp[x][i]=(solve('e',i+2)+solve('a',i+2)+solve('i',i+2)+solve('i',i+1)+solve('i',i+2)+solve('u',i+2)+solve('a',i+2))%m;
        }
        else if(prev=='a'){
            return dp[x][i]=solve('e',i+1)%m;
        }
        else if(prev=='e'){
            return dp[x][i]=(solve('a',i+1)+solve('i',i+1))%m;
        }
        else if(prev=='i'){
            return dp[x][i]=(solve('a',i+1)+solve('e',i+1)+solve('u',i+1)+solve('o',i+1))%m;
        }
        else if(prev=='o'){
            return dp[x][i]=(solve('i',i+1)+solve('u',i+1))%m;
        }
        else if(prev=='u'){
            return dp[x][i]=solve('a',i+1)%m;
        }
        return dp[x][i]=0;
    }
    int countVowelPermutation(int nn) {
        n=nn;
        memset(dp,-1,sizeof(dp));
        return solve('#',0);
    }
};