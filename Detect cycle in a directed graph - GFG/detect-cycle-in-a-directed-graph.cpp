// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    int cyc=0;
    void dfs(vector<int> &vis,vector<int> &visSt,vector<int> adj[],int node){
        vis[node]=visSt[node]=1;
        for(auto neigh: adj[node]){
            if(visSt[neigh])cyc=1;
            if(!vis[neigh])dfs(vis,visSt,adj,neigh);
        }
        visSt[node]=0;
    }
    bool isCyclic(int v, vector<int> adj[]) {
         vector<int> vis(v,0),visSt(v,0);
         for(int i=0;i<v;i++){
             dfs(vis,visSt,adj,i);
         }
         return cyc;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends