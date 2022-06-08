class Solution {
public:
    bool isp(string s){
        for(int i=0;i<s.size()/2;i++)if(s[i]!=s[s.size()-i-1])return 0;
        return 1;
    }
    int removePalindromeSub(string s) {
        if(s.size()==0)return 0;
        if(isp(s))return 1;
        return 2;
    }
};