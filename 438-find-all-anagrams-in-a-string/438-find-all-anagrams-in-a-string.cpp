class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> v,x(26),y(26);
        if(p.size()>s.size())return {};
        for(int i=0;i<p.size();i++){
            x[s[i]-'a']++;
            y[p[i]-'a']++;
        }
        for(int i=0;i<=s.size()-p.size();i++){
            if(i!=0){
                x[s[i-1]-'a']--;
                x[s[i+p.size()-1]-'a']++;
            }
            bool f=1;
            for(int j=0;j<26;j++){
                if(x[j]!=y[j]){
                    f=0;
                    break;
                }
            }
            if(f)v.push_back(i);
        }
        return v;
    }
};