class Solution {
public:
    vector<int> g[100005]; 
    bool vis[100005];
    void dfs(int n){
        vis[n]=1;
        for(auto x : g[n]){
            if(!vis[x])dfs(x);
        }
    }
    int makeConnected(int n, vector<vector<int>>& c) {
        if(c.size()<n-1)return -1;
        for(int i=0;i<c.size();i++){
            g[c[i][0]].push_back(c[i][1]);
            g[c[i][1]].push_back(c[i][0]);
        }
        int com=0;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                dfs(i);
                com++;
            }
        }
        return com-1;
    }
};