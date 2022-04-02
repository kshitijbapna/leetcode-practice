class Solution {
public:
    bool isp(string s){
        for(int i=0;i<s.size()/2;i++)if(s[i]!=s[s.size()-i-1])return 0;
        return 1;
    }
    bool validPalindrome(string s) {
        int n=s.size();
        if(isp(s))return 1;
        for(int i=0;i<n/2;i++){
            if(s[i]!=s[n-i-1]){
                string str1=s,str2=s;
                str1.erase(str1.begin()+i);
                str2.erase(str2.begin()+n-i-1);
                if(isp(str1)||isp(str2))return 1;
                break;
            }
        }
        return 0;
    }
};