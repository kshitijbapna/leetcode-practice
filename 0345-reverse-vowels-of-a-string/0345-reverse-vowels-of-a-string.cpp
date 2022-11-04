class Solution {
public:
    bool vowel(char c){
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U')return 1;
        return 0;
    }
    string reverseVowels(string s) {
        int j=s.size()-1;
        for(int i=0;i<s.size();i++){
            if(vowel(s[i])){
                while(j>i&&vowel(s[j])==0){
                    j--;
                }
                if(j>i)swap(s[i],s[j]);
                j--;
            }
        }
        return s;
    }
};