class Solution {
public:
    int ans=0;
    int dir[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
    bool vis[51][51];
    void bfs(vector<vector<int>>& g,int area,int i,int j){
        int n=g.size(),m=g[0].size();
        queue<pair<int,int>> q;
        q.push({i,j});
        // area++;
        while(q.size()>0){
            pair<int,int> p=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int xx=p.first+dir[i][0],yy=p.second+dir[i][1];
                if(xx>=0&&xx<n&&yy>=0&&yy<m&&g[xx][yy]&&vis[xx][yy]==0){
                    q.push({xx,yy});
                    vis[xx][yy]=1;
                    area++;
                }
            }
        }
        ans=max(ans,1);
        // cout<<i<<" "<<j<<" "<<area<<"\n";
        ans=max(ans,area);
    }
    int maxAreaOfIsland(vector<vector<int>>& g) {
        int n=g.size(),m=g[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(g[i][j]&&vis[i][j]==0){
                    bfs(g,0,i,j);
                }
            }
        }
        return ans;
    }
};