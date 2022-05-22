class Solution {
public:
    
    int countSubstrings(string s) {
        int ans=0,n=s.size();
        for(int i=0;i<n;i++){
            int l=i,r=i;
            while(l>=0&&r<n){
                if(s[l]==s[r])ans++;
                else break;
                l--;
                r++;
            }
            l=i-1,r=i;
            while(l>=0&&r<n){
                if(s[l]==s[r])ans++;
                else break;
                l--;
                r++;
            }
        }
        return ans;
    }
};