// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int help(int i,int j,vector<vector<int>> &m,int xd,int yd){
        if(i==xd&&j==yd)return 0;
        if(i<0||i>=m.size()||j<0||j>=m[0].size())return -1e9;
        if(m[i][j]!=1)return -1e9;
        m[i][j]=0;
        int r=1+help(i,j+1,m,xd,yd);
        int l=1+help(i,j-1,m,xd,yd);
        int u=1+help(i-1,j,m,xd,yd);
        int d=1+help(i+1,j,m,xd,yd);
        m[i][j]=1;
        return max({r,l,u,d});
    }
    int longestPath(vector<vector<int>> m, int xs, int ys, int xd, int yd)
    {
        if(m[xs][ys]==0||m[xd][yd]==0)return -1;
        int ans=help(xs,ys,m,xd,yd);
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
        int xs, ys, xd, yd;
        cin >> xs >> ys >> xd >> yd;
        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> mat[i][j];
            }
        }
        Solution ob;
        int ans = ob.longestPath(mat, xs, ys, xd, yd);
        cout << ans;
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends