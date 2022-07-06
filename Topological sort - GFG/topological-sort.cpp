// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	
	/*Using dfs*/
	
// 	void tsort(int node,vector<int> &ans,vector<int> adj[],vector<bool> &vis){
// 	    vis[node]=1;
// 	    for(auto n : adj[node]){
// 	        if(!vis[n]){
// 	            tsort(n,ans,adj,vis);
// 	        }
// 	    }
// 	    ans.push_back(node);
// 	}
// 	vector<int> topoSort(int V, vector<int> adj[]) 
// 	{
// 	   vector<int> ans;
// 	    vector<bool> vis(V);
// 	    for(int i=0;i<V;i++){
// 	        if(!vis[i]){
// 	            tsort(i,ans,adj,vis);
// 	        }
// 	    }
// 	    reverse(ans.begin(),ans.end());
// 	    return ans;
// 	}


/*Using bfs*/
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> ans;
	    vector<int> vis(V),in(V);
	    for(int i=0;i<V;i++){
	        for(auto x : adj[i]){
	            in[x]++;
	        }
	    }
	    queue<int> q;
	    for(int i=0;i<V;i++){
	        if(in[i]==0){
	            q.push(i);
	            vis[i]=1;
	        }
	    }
	    while(q.size()>0){
	        int x=q.front();
	        q.pop();
	        ans.push_back(x);
	        for(auto neigh : adj[x]){
	            if(!vis[neigh]){
	                in[neigh]--;
	                if(in[neigh]==0){
	                    q.push(neigh);
	                    vis[neigh]=1;
	                }
	            }
	        }
	    }
	   // for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
	    return ans;
	}
    
};

// { Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}  // } Driver Code Ends