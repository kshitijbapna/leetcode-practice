// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    // vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    // {
    //     vector<int> dis(V,1e7);
    //     dis[S]=0;
    //     set<pair<int,int>> s;
    //     for(int i=0;i<V;i++){
    //         if(i==S)s.insert({0,S});
    //         else s.insert({1e7,i});
    //     }
    //     while(!s.empty()){
    //         pair<int,int> tmp=*s.begin();
    //         s.erase(s.begin());
    //         int d=tmp.first,u=tmp.second;
    //         for(auto i : adj[u]){
    //             int v=i[0],wt=i[1];
    //             if(dis[v]>dis[u]+wt){
    //                 s.erase(s.find({dis[v],v}));
    //                 s.insert({dis[u]+wt,v});
    //                 dis[v]=dis[u]+wt;
    //             }
    //         }
    //     }
    //     return dis;
    // }
    
    //using priority queue
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int> dis(V,1e7);
        dis[S]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i=0;i<V;i++){
            if(i==S)pq.push({0,S});
        }
        while(!pq.empty()){
            pair<int,int> x=pq.top();
            pq.pop();
            for(auto neigh : adj[x.second]){
                if(x.first+neigh[1]<dis[neigh[0]]){
                    dis[neigh[0]]=x.first+neigh[1];
                    pq.push({dis[neigh[0]],neigh[0]});
                }
            }
        }
        return dis;
    }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends