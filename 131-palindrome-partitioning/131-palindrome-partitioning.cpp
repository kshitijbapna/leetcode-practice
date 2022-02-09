class Solution {
public:
    bool isPal(string s){
        for(int i=0;i<s.size()/2;i++){
            if(s[i]!=s[s.size()-i-1])return 0;
        }
        return 1;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        if(s.size()==0){
            ans.push_back({});
            return ans;
        }
        for(int i=s.size()-1;i>=0;i--){
            string ss=s.substr(i);
            // cout<<ss<<" ";
            if(isPal(ss)){
                vector<vector<string>> temp=partition(s.substr(0,i));
                for(auto it: temp){
                    it.push_back(ss);
                    ans.push_back(it);
                }
            }
        }
        return ans;
    }
};