// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
    char d[4]={'D','U','R','L'};
    vector<string> ans;
    void dfs(vector<vector<int>>& m,int n,int x,int y,vector<vector<int>> vis,string path){
        if(x==n-1&&y==n-1&&m[x][y])ans.push_back(path);
        vis[x][y]=1;
        for(int i=0;i<4;i++){
            int xx=x+dir[i][0],yy=y+dir[i][1];
            if(xx>=0&&yy>=0&&xx<n&&yy<n&&vis[xx][yy]==0&&m[xx][yy]){
                string np=path;
                np+=d[i];
                dfs(m,n,xx,yy,vis,np);
            }
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<vector<int>> vis(n,vector<int>(n,0));
        if(m[0][0])dfs(m,n,0,0,vis,"");
        sort(ans.begin(),ans.end());
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends