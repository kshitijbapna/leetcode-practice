class Solution {
public:
    string pushDominoes(string s) {
        s='L'+s+'R';
        string res;
        int i=0;
        for(int j=1;j<s.size();j++){
            if(s[j]=='.')
                continue;
            int mid=j-i-1;
            if(i>0)
                res+=s[i];
            if(s[i]==s[j])
                res+=string(mid,s[i]);
            else if(s[i]=='L'&&s[j]=='R')
                res+=string(mid,'.');
            else res+=string(mid/2,'R')+string(mid%2,'.')+string(mid/2,'L');
            i=j;
        }
        return res;
    }
};