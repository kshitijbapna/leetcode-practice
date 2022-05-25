class Solution {
public:
    int ans=0,vis[101][101];
    int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
    void bfs(vector<vector<int>>& g,int i,int j){
        int n=g.size(),m=g[0].size();
        bool f=1;
        queue<pair<int,int>> q;
        q.push({i,j});
        vis[i][j]=1;
        while(q.size()>0){
            pair<int,int> p=q.front();
            q.pop();
            int i=p.first,j=p.second;
            if(i==0||i==n-1||j==0||j==m-1)f=0;
            for(int ii=0;ii<4;ii++){
                int x=i+dir[ii][0],y=j+dir[ii][1];
                if(x>=0&&x<n&&y>=0&&y<m&&g[x][y]==0&&vis[x][y]==0){
                    q.push({x,y});
                    vis[x][y]=1;
                }
            }    
        }
        if(f)ans++;
    }
    int closedIsland(vector<vector<int>>& g) {
        int n=g.size(),m=g[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(g[i][j]==0&&vis[i][j]==0){
                    bfs(g,i,j);
                }
            }
        }
        return ans;
    }
};