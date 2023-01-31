class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>> v;
        for(int i=0;i<ages.size();i++)
            v.push_back({ages[i],scores[i]});
        sort(v.begin(),v.end(),greater<>());
        int ans=0,n=ages.size();
        vector<int> dp(n);
        for(int i=0;i<n;i++){
            int score=v[i].second;
            dp[i]=score;
            for(int j=0;j<i;j++){
                if(v[j].second>=score){
                    dp[i]=max(dp[i],dp[j]+score);
                }
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};