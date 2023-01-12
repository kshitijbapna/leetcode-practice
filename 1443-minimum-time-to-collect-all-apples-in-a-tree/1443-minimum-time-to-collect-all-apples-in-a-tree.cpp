class Solution {
public:
    vector<int> adj[100005];
    int dfs(int node,int cost,vector<bool>& vis,vector<bool> &app){
        if(vis[node])
            return 0;
        vis[node]=1;
        int childrenCost=0;
        for(auto x : adj[node]){
            childrenCost+=dfs(x,2,vis,app);
        }
        if(childrenCost==0&&app[node]==0)
            return 0;
        return cost+childrenCost;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<bool> vis(n);
        for(auto &x : edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        return dfs(0,0,vis,hasApple);
    }
};