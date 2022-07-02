class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        int i=0;
        while(i<s.size()){
            if(i==0){
                while(s[0]==' ')s.erase(s.begin());
            }
            else{
                if(s[i]==' '){
                    while(i<s.size()&&s[i+1]==' ')s.erase(s.begin()+i+1);
                }
                i++;
            }
            int st=i,en=i;
            while(en<s.size()&&s[en]!=' ')en++;
            int next=en;
            en--;
            while(st<en){
                swap(s[st++],s[en--]);
            }
            i=next;
        }
        while(s[s.size()-1]==' ')s.erase(s.begin()+s.size()-1);
        return s;
    }
};