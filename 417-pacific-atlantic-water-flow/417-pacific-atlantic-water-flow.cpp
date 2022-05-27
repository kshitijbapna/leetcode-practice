class Solution {
public:
    void bfs(vector<vector<int>>& h,vector<vector<bool>> &vis,int i,int j){
        if(vis[i][j])return;
        int n=h.size(),m=h[0].size();
        queue<pair<int,int>> q;
        q.push({i,j});
        vis[i][j]=1;
        while(q.size()>0){
            auto [sx,sy]=q.front();
            q.pop();
            for(int ii=0;ii<4;ii++){
                int xx=sx+dir[ii][0],yy=sy+dir[ii][1];
                if(xx>=0&&xx<n&&yy>=0&&yy<m&&vis[xx][yy]==0&&h[xx][yy]>=h[sx][sy]){
                    vis[xx][yy]=1;
                    q.push({xx,yy});
                }
            }
        }
    }
    int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        int n=h.size(),m=h[0].size();
        vector<vector<bool>> v1(n,vector<bool>(m,0));
        vector<vector<bool>> v2(n,vector<bool>(m,0));
        vector<vector<int>> res;
        // for(int i=0;i<n;i++)v1[i][0]=1,v2[i][m-1];
        // for(int i=0;i<m;i++)v1[0][i]=1,v2[n-1][i];
        
        for(int i=0;i<n;i++){
            bfs(h,v1,i,0);
            bfs(h,v2,i,m-1);
        }
        for(int i=0;i<m;i++){
            bfs(h,v1,0,i);
            bfs(h,v2,n-1,i);
        }
        for(int i=0;i<n;i++)for(int j=0;j<m;j++){
            if(v1[i][j]&&v2[i][j]){
                vector<int> k{i,j};
                res.push_back(k);
            }
        }
        return res;
    }
};