class Solution {
public:
    vector<char> adj[26];
    void dfs(int node,vector<char> &mn,vector<bool> &vis,char found){
        if(vis[node])
            return;
        vis[node]=1;
        found=min(found,(char)('a'+node));
        for(auto x : adj[node]){
            if(!vis[x-'a']){
                dfs(x-'a',mn,vis,found);
            }
        }
        mn[node]=found;
    }
    string smallestEquivalentString(string s1, string s2, string s) {
        int n=s1.size();
        for(int i=0;i<n;i++){
            adj[s1[i]-'a'].push_back(s2[i]);
            adj[s2[i]-'a'].push_back(s1[i]);
        }
        vector<bool> vis(26);
        vector<char> mn(26);
        for(int i=0;i<26;i++){
            char found='z';
            if(!vis[i])
                dfs(i,mn,vis,found);
        }
        for(int i=0;i<s.size();i++){
            s[i]=mn[s[i]-'a'];
        }
        return s;
    }
};