class Solution {
public:
    set<string> words;
    vector<string> ans;
    void solve(int i,string &s,string t,string curr){
        if(i>=s.size())return;
        t+=s[i];
        solve(i+1,s,t,curr);
        if(words.find(t)!=words.end()){
            curr+=t;
            if(i!=s.size()-1)curr+=" ";
            else ans.push_back(curr);
            t="";
            solve(i+1,s,t,curr);
        }
        
    }
    vector<string> wordBreak(string s, vector<string>& dict) {
        for(auto word : dict)
        words.insert(word);
        string t,curr;
        solve(0,s,t,curr);
        return ans;
    }
};