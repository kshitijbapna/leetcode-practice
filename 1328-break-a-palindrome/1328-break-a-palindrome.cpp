class Solution {
public:
    bool palin(string &s){
        int i=0,j=s.size()-1;
        while(i<j){
            if(s[i]!=s[j])return 0;
            i++;
            j--;
        }
        return 1;
    }
    string breakPalindrome(string p) {
        int n=p.size();
        if(p.size()==1){
            return "";
        }
        set<string> s;
        for(int i=0;i<p.size();i++){
            for(char a='a';a<='y';a++){
                string y=p;
                y[i]=a;
                if(!palin(y))s.insert(y);
            }
        }
        return *s.begin();
    }
};