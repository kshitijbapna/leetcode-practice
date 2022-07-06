// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool cyc=0;
    bool vis[100002];
    void dfs(vector<int> adj[],int node,int parent){
        vis[node]=1;
        for(auto x : adj[node]){
            if(vis[x]&&x!=parent)cyc=1;
            if(!vis[x])dfs(adj,x,node);
        }
    }
    bool isCycle(int V, vector<int> adj[]) {
        memset(vis,0,sizeof(vis));
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(adj,i,-1);
            }
        }
        return cyc;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends