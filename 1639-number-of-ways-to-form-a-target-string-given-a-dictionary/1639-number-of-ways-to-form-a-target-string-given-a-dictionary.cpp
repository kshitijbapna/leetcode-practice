class Solution {
public:
    int mm=1e9+7;
    long solve(map<char,int> mp[],int j,int i,string &target,vector<vector<int>> &dp,int n){
      //base conditions
      if(i==target.size())return 1; 
      if(j==n)return 0;
      //return if already done 
      if(dp[j][i]!=-1)return dp[j][i]%mm; 
      //if present at current index
      if(mp[j][target[i]]>0){
        return dp[j][i]=((long)mp[j][target[i]]*solve(mp,j+1,i+1,target,dp,n)%mm+solve(mp,j+1,i,target,dp,n)%mm)%mm;
      }
      //not present at current idx
      return dp[j][i]=solve(mp,j+1,i,target,dp,n)%mm;
    }
    int numWays(vector<string>& words, string target) {
        int n=words[0].size();
          map<char,int> mp[n];
          for(int i=0;i<words.size();i++){ 
            for(int j=0;j<n;j++){
              mp[j][words[i][j]]++;
            }
          }

          vector<vector<int>> dp(n,vector<int>(target.size(),-1)); 
          return solve(mp,0,0,target,dp,n);
    }
};