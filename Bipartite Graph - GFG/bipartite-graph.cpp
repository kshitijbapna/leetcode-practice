// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	bool isBipartite(int V, vector<int>adj[]){
	    int n=V;
	    vector<int> color(n);
	    queue<int> q;
	    for(int i=0;i<n;i++){
	        if(color[i])continue;
	        color[i]=1;
	        q.push(i);
	        while(!q.empty()){
	            int cur=q.front();
	            q.pop();
	            for(int neigh : adj[cur]){
	                if(!color[neigh]){
	                    color[neigh]=-color[cur];
	                    q.push(neigh);
	                }
	                else if(color[neigh]==color[cur]){
	                    return 0;
	                }
	            }
	        }
	        
	    }
	    return 1;
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends