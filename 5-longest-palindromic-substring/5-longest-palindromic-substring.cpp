class Solution {
public:
    string longestPalindrome(string s) {
        int len=1,l,r,cl,n=s.size();
        string ans;
        ans+=s[0];
        for(int i=0;i<n;i++){
            l=i-1,r=i+1,cl=1;
            while(l>=0&&r<n&&s[l]==s[r]){
                cl+=2;
                if(cl>len){
                    len=cl;
                    ans=s.substr(l,cl);
                }
                l--;
                r++;
            }
            l=i,r=i+1,cl=0;
            while(l>=0&&r<n&&s[l]==s[r]){
                cl+=2;
                // cout<<"here";
                if(cl>len){
                    len=cl;
                    ans=s.substr(l,cl);
                }
                l--;
                r++;
            }
        }
        return ans;
    }
};