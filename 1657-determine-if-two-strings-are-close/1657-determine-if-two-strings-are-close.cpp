class Solution {
public:
    bool closeStrings(string word1, string word2) {
        map<int,int> m1,m2;
        for(auto x : word1)m1[x-'a']++;
        for(auto x : word2)m2[x-'a']++;
        vector<int> v1,v2,v3,v4;
        for(auto x : m1){v1.push_back(x.second);v3.push_back(x.first);}
        for(auto x : m2){v2.push_back(x.second);v4.push_back(x.first);}
        sort(v1.begin(),v1.end());sort(v2.begin(),v2.end());
        sort(v3.begin(),v3.end());sort(v4.begin(),v4.end());
        if(v1.size()!=v2.size())return 0;
        for(int i=0;i<v1.size();i++){
            if(v1[i]!=v2[i])return 0;
        }
        if(v3.size()!=v4.size())return 0;
        for(int i=0;i<v3.size();i++){
            if(v3[i]!=v4[i])return 0;
        }
        return 1;
    }
};