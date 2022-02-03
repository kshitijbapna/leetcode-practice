class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int mx=0,i=0,j=0,n=s.size();
        int vis[256];
        memset(vis,0,sizeof(vis));
        while(i<n){
            while(j<n&&vis[s[j]]==0){
                mx=max(mx,j-i+1);
                vis[s[j]]=1;
                j++;
            }
            vis[s[i]]=0;
            i++;
        }
        return mx;
    }
};