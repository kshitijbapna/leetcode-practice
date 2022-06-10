// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    void dfs(vector<vector<char>>& g,int x,int y){
        g[x][y]=-1;
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                int xx=x+i,yy=y+j;
                if(xx>=0&&yy>=0&&xx<g.size()&&yy<=g[0].size()&&g[xx][yy]=='1'){
                    dfs(g,xx,yy);
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& g) {
        int ans=0,n=g.size(),m=g[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(g[i][j]=='1'){
                    dfs(g,i,j);
                    ans++;
                }
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}  // } Driver Code Ends