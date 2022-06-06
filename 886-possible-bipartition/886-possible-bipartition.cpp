class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n+1);
        vector<int> color(n+1,0);
        vector<bool> explored(n+1,0);
        
        for(auto x: dislikes){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        
        queue<int> q;
        for(int i=1;i<=n;i++){
            if(!explored[i]){
                color[i]=1;
                q.push(i);
                while(!q.empty()){
                    int u=q.front();
                    q.pop();
                    if(explored[u])continue;
                    explored[u]=1;
                    for(auto v : adj[u]){
                        if(color[v]==color[u])return 0;
                        color[v]=-color[u];
                        q.push(v);
                    }
                }
            }
        }
        return 1;
    }
};