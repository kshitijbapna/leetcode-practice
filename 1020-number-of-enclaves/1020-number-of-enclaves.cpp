class Solution {
public:
    int ans=0;
    int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
    bool vis[505][505];
    void bfs(vector<vector<int>>& g,int x,int y){
        int k=0,n=g.size(),m=g[0].size();
        bool f=1;
        queue<pair<int,int>> q;
        q.push({x,y});
        vis[x][y]=1;
        while(q.size()>0){
            pair<int,int> p=q.front();
            q.pop();
            k++;
            if(p.first==0||p.first==n-1||p.second==0||p.second==m-1)f=0;
            for(int i=0;i<4;i++){
                int xx=p.first+dir[i][0],yy=p.second+dir[i][1];
                if(xx>=0&&xx<n&&yy>=0&&yy<m&&g[xx][yy]&&vis[xx][yy]==0){
                    q.push({xx,yy});
                    vis[xx][yy]=1;
                }
            }
        }
        // cout<<f<<" "<<x<<" "<<y<<" "<<k<<"\n";
        if(f)ans+=k;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]&&grid[i][j])bfs(grid,i,j);
            }
        }
        return ans;
    }
};