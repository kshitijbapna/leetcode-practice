class Solution {
public:
    bool f=1;
    vector<int> col,vis;
    void dfs(vector<vector<int>>& adj,int n,int c){
        vis[n]=1;
        col[n]=c;
        for(auto x : adj[n]){
            if(col[x]==c)f=0;
            if(!vis[x]){
                // cout<<n<<" "<<x<<" "<<c<<"\n";
                dfs(adj,x,1-c);
            }
        }
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n); // 0: uncolored; 1: color A; -1: color B

        queue<int> q; // queue, resusable for BFS    

        for (int i = 0; i < n; i++) {
          if (color[i]) continue; // skip already colored nodes

          // BFS with seed node i to color neighbors with opposite color
          color[i] = 1; // color seed i to be A (doesn't matter A or B) 
          for (q.push(i); !q.empty(); q.pop()) {
            int cur = q.front();
            for (int neighbor : graph[cur]) 
            {
              if (!color[neighbor]) // if uncolored, color with opposite color
              { color[neighbor] = -color[cur]; q.push(neighbor); } 

              else if (color[neighbor] == color[cur]) 
                return false; // if already colored with same color, can't be bipartite!
            }        
          }
    }
    
    return true;
    }
};