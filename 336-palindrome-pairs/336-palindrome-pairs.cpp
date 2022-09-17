class Solution {
public:
    bool isP(string &s,int l,int r){
        while(l<r){
            if(s[l]!=s[r])return 0;
            l++;r--;
        }
        return 1;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> ans;
        unordered_map<string,int> m;
        set<int> s;
        for(int i=0;i<words.size();i++){
            m[words[i]]=i;
            s.insert(words[i].size());
        }
        for(int i=0;i<words.size();i++){
            string str=words[i];
            int sz=str.size();
            reverse(str.begin(),str.end());
            if(m.count(str)&&m[str]!=i){
                ans.push_back({i,m[str]});
            }
            auto a=s.find(sz);
            for(auto it=s.begin();it!=a;it++){
                int d=*it;
                if(isP(str,0,sz-d-1)&&m.count(str.substr(sz-d))){
                    ans.push_back({i,m[str.substr(sz-d)]});
                }
                if(isP(str,d,sz-1)&&m.count(str.substr(0,d))){
                    ans.push_back({m[str.substr(0,d)],i});
                }
            }
        }
        return ans;
    }
};