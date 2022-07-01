// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public: 
    vector<int> adj[20];
    int cnt=0;
    void dfs(int n,int e){
        if(n==e){
            cnt++;
            return;
        }
        for(auto x : adj[n]){
            dfs(x,e);
        }
    }
	int possible_paths(vector<vector<int>>edges, int n, int s, int d){
	    for(auto edge: edges){
	        adj[edge[0]].push_back(edge[1]);
	    }
	    dfs(s,d);
	    return cnt;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, s, d;
		cin >> n >> m >> s >> d;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int u, v;
			cin >> u >> v;
			edges.push_back({u,v});
		}
		Solution obj;
		int ans = obj.possible_paths(edges, n, s, d);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends