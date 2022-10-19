// bool cmp(pair<int,string> a,pair<int,string> b){
    
// }
auto cmp=[](pair<int,string> a,pair<int,string> b){
    if(a.first==b.first)return a.second>b.second;
    return a.first<b.first;
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> m;
        for(auto word : words){
            m[word]++;
        }
        set<pair<int,string>,decltype(cmp)> s(cmp);
        for(auto x : m){
            if(s.size()<k)
                s.insert({x.second,x.first});
            else{
                if((*s.begin()).first<x.second){
                    s.erase(s.begin());
                    s.insert({x.second,x.first});
                }
                else if((*s.begin()).first==x.second&&(*s.begin()).second>x.first){
                    s.erase(s.begin());
                    s.insert({x.second,x.first});
                }
            }
        }
        vector<string> ans;
        while(s.size()!=0){
            ans.push_back((*s.begin()).second);
            s.erase(s.begin());
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};