class Solution {
public:
    vector<int> adj[100005];
    int ans=1;
    int dfs(string &s,int node){
        if(adj[node].size()==0)
            return 1;
        int mx1=0,mx2=0;
        for(auto x : adj[node]){
            int len=dfs(s,x);
            ans=max(ans,len);
            if(s[x]==s[node])
                continue;
            if(len>mx1){
                mx2=mx1;
                mx1=len;
            }
            else{
                mx2=max(mx2,len);
            }
        }
        ans=max(ans,1+mx1+mx2);
        return 1+mx1;
    }
    int longestPath(vector<int>& parent, string s) {
        int n=parent.size();
        for(int i=1;i<n;i++)
            adj[parent[i]].push_back(i);
        dfs(s,0);
        return ans;
    }
};