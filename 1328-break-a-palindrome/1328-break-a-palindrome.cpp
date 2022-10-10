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
        if(n==1)return "";
        int done=0;
        for(char x='a';x<='y';x++){
            for(int i=0;i<n;i++){
                if(p[i]>x){
                    char tmp=p[i];
                    p[i]=x;
                    if(!palin(p)){
                        done=1;
                        break;
                    }
                    else{
                        p[i]=tmp;
                    }
                }
            }
            if(done)break;
        }
        if(done==0){
            p[n-1]='b';
        }
        return p;
    }
};