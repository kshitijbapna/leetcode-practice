// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    vector<int> adj[10004];
    int vis[10004],vvis[10004];
    bool detectcycle(int node)
      {
          vis[node] = 1;
          vvis[node] = 1;
          
          for(int i = 0;i<adj[node].size();i++)
          {
              if(vis[adj[node][i]] == 0)
              {
                  if(detectcycle(adj[node][i])) return true;
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
        
        int p = pre.size();
        memset(vis,0,sizeof(vis));
        memset(vis,0,sizeof(vvis));
        
        for(int i = 0;i<p;i++)
        {
            int a , b;
            a = pre[i].first ;
            b = pre[i].second;
            adj[b].push_back(a);
        }
        
        for(int i = 0;i<N;i++)
        {
            if(!vis[i])
            {
                if(detectcycle(i)) return false;
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