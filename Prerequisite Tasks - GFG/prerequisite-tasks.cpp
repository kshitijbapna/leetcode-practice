// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int vis[10004];
    bool detectcycle(vector<int> adj[],int n,vector<int> &vvis,int node)
      {
          vis[node] = 1;
          vvis[node] = 1;
          
          for(int i = 0;i<adj[node].size();i++)
          {
              if(vis[adj[node][i]] == 0)
              {
                  if(detectcycle(adj,n,vvis,adj[node][i])) return true;
              }
              else if(vvis[adj[node][i]])
              {
                  return true;
              }
          }
          vvis[node] = 0;
          return false;
      }
    
    bool isPossible(int N, vector<pair<int, int> >& pre) 
    {
        // Code here
        vector<int> adj[N];
        int p = pre.size();
        memset(vis,0,sizeof(vis));
        
        for(int i = 0;i<p;i++)
        {
            int a , b;
            a = pre[i].first ;
            b = pre[i].second;
            adj[b].push_back(a);
        }
        
        vector<int> vvis(N,0) ;
        
        for(int i = 0;i<N;i++)
        {
            if(!vis[i])
            {
                if(detectcycle(adj,N,vvis,i)) return false;
            }
        }
        
        return true;
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