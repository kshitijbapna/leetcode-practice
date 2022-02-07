class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> v(26),u(26);
        for(int i=0;i<s.size();i++){
            v[s[i]-'a']++;
            u[t[i]-'a']++;
        }
        u[t[t.size()-1]-'a']++;
        for(int i=0;i<26;i++){
            if(u[i]>v[i])return (char)(i+'a');
        }
        return 'a';
    }
};