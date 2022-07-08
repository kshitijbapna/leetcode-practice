class Solution {
public:
    int numSplits(string s) {
        int n=s.size();
        map<char,int> m1,m2;
        m1[s[0]]++;
        for(int i=1;i<n;i++){
            m2[s[i]]++;
        }
        int ans=0;
        for(int i=1;i<n;i++){
            if(m1.size()==m2.size())ans++;
            m1[s[i]]++;
            m2[s[i]]--;
            if(m2[s[i]]==0)m2.erase(m2.find(s[i]));
        }
        return ans;
    }
};