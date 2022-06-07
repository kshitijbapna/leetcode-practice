// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int v, vector<int> adj[]) {
         vector<int>in(v,0);
         for(int i=0;i<v;i++){
             for(auto x:adj[i]){
                 in[x]++;
             }
         }
         queue<int>q;
         for(int i=0;i<v;i++){
             if(in[i]==0) 
            q.push(i);
         }
         int c=0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
          
            c++;
            for(auto it : adj[node]){
                in[it]--;
                if(in[it] == 0){
                    q.push(it);
                }
            }
        }
         return c!=v;
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