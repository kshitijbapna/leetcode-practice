// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int vis[10004],st[10004];
    vector<int> adj[10005];
    bool cycle(int node){
        vis[node]=1;
        st[node]=1;
        
        for(auto nbr : adj[node]){
            if(st[nbr])return 1;
            else if(vis[nbr]==0){
                bool cyc=cycle(nbr);
                if(cyc)return 1;
            }
        }
        
        st[node]=0;
        return 0;
    }
	bool isPossible(int N, vector<pair<int, int> >& p) {
	    memset(vis,0,sizeof(vis));memset(st,0,sizeof(st));
	    for(auto x : p){
	        adj[x.first].push_back(x.second);
	    }
	    for(int i=0;i<N;i++){
	        if(vis[i]==0){
	            if(cycle(i))return 0;
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
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}  // } Driver Code Ends