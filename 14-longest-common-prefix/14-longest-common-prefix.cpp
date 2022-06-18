class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans=strs[0];
        for(int i=1;i<strs.size();i++){
            string nw;
            for(int j=0;j<min(strs[i].size(),ans.size());j++){
                if(strs[i][j]==ans[j])nw+=strs[i][j];
                else break;
            }
            ans=nw;
        }
        return ans;
    }
};