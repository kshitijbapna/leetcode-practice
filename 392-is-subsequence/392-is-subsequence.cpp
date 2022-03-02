class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0,j=0,n=s.size(),m=t.size();
        if(n==0)return 1;
        if(m==0)return 0;
        while(1){
            if(s[i]==t[j]){
                i++;
                j++;
            }else{
                j++;
            }
            if(i>=n)break;
            if(j>=m)break;
        }
        if(i>=n)return 1;
        return 0;
    }
};