class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> m;
        for(auto ch : t)m[ch]++;
        int st=0,en=0,cnt=t.size(),minSt=0,minLen=INT_MAX,sz=s.size();
        while(en<sz){
            if(m[s[en]]>0)cnt--;
            m[s[en]]--;
            en++;
            while(cnt==0){
                if(en-st<minLen){
                    minSt=st;
                    minLen=en-st;
                }
                m[s[st]]++;
                if(m[s[st]]>0)cnt++;
                st++;
            }
        }
        if(minLen!=INT_MAX)return s.substr(minSt,minLen);
        return "";
    }
};