class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> m;
        for(auto word : words){
            m[word]++;
        }
        set<pair<int,string>> s;
        for(auto x : m){
            s.insert({-x.second,x.first});
        }
        vector<string> ans;
        for(int i=0;i<k;i++){
            string y=(*s.begin()).second;
            ans.push_back(y);
            s.erase(s.begin());
        }
        return ans;
    }
};