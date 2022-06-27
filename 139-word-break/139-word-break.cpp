class Solution {
public:
    set<string> di;
    bool wordBreak(string s, vector<string>& dict) {
        set<string> Dict(dict.begin(),dict.end());
        if(dict.size()==0)return 0;
        vector<bool> dp(s.size()+1,0);
        dp[0]=1;
        for(int i=1;i<=s.size();i++){
            for(int j=i-1;j>=0;j--){
                if(dp[j]){
                    string w=s.substr(j,i-j);
                    if(Dict.find(w)!=Dict.end()){
                        dp[i]=1;
                        break;
                    }
                }
            }
        }
        return dp[s.size()];
    }
};