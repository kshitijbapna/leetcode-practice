class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1)return -1;
        int n=grid.size(),m=grid[0].size(),dis[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)dis[i][j]=INT_MAX;
        }
        queue<pair<int,int>> q;
        q.push({0,0});
        dis[0][0]=1;
        while(!q.empty()){
            pair<int,int> x=q.front();
            q.pop();
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    if(i==0&&j==0)continue;
                    int xx=x.first+i;
                    int yy=x.second+j;
                    if(xx>=0&&xx<n&&yy>=0&&yy<m&&grid[xx][yy]==0&&dis[xx][yy]==INT_MAX){
                        dis[xx][yy]=dis[x.first][x.second]+1;
                        q.push({xx,yy});
                    }
                }
            }
        }
        if(dis[n-1][m-1]==INT_MAX)dis[n-1][m-1]=-1;
        return dis[n-1][m-1];
    }
};