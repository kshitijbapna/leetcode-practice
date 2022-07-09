// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    vector<vector<int>> ans;
    int dir[2][2]={{1,0},{0,1}};
    void dfs(vector<int> curr,int i,int j,vector<vector<int>> &grid){
        int n=grid.size(),m=grid[0].size();
        if(i>=n||j>=m||i<0||j<0)return;
        curr.push_back(grid[i][j]);
        if(i==n-1&&j==m-1){
            ans.push_back(curr);
            return;
        }
        dfs(curr,i+1,j,grid);
        dfs(curr,i,j+1,grid);
    }
    vector<vector<int>> findAllPossiblePaths(int n, int m, vector<vector<int>> &grid)
    {
        vector<int> curr;
        dfs(curr,0,0,grid);
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution ob;
        auto ans = ob.findAllPossiblePaths(n, m, grid);
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
  // } Driver Code Ends