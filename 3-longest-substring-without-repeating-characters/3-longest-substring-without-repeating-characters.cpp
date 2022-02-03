class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,j=0,n=s.size(),ans=min(1,n);
        for(int i=0;i<n;i++){
            set<char> se;
            se.insert(s[i]);
            for(int j=i+1;j<n;j++){
                se.insert(s[j]);
                if(se.size()==j-i+1)ans=max(ans,j-i+1);
                else break;
            }
        }
        return ans;
    }
};