// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size(),ans=0,fresh=0;
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2)q.push({i,j});
                else if(grid[i][j]==1)fresh++;
            }
        }
        while(!q.empty()){
            ans++;
            int sz=q.size();
            while(sz--){
                pair<int,int> xx=q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int x=xx.first+dir[i][0],y=xx.second+dir[i][1];
                    if(x>=0&&y>=0&&y<m&&x<n&&grid[x][y]==1){
                        grid[x][y]=2;
                        fresh--;
                        q.push({x,y});
                    }
                }
            }
            if(fresh==0)return ans;
        }
        return -1;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends