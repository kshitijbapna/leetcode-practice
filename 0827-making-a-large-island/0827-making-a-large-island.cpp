class Solution {
public:
    vector<vector<int>> vis;
    int cnt,dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}},curr=0;
    void dfs(vector<vector<int>> &g,int i,int j){
        int n=g.size(),m=g[0].size();
        // cout<<"here\t";
        if(i<0||i>=n||j<0||j>=m)return;
        vis[i][j]=curr;
        cnt++;
        for(int ii=0;ii<4;ii++){
            int xx=dir[ii][0]+i,yy=dir[ii][1]+j;
            if(xx>=0&&xx<n&&yy>=0&&yy<m&&g[xx][yy]==1&&vis[xx][yy]==-1){
                dfs(g,xx,yy);
            }
        }
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vis=grid;
        for(int i=0;i<n;i++)for(int j=0;j<m;j++)vis[i][j]=-1;
        map<int,int> mp;
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1&&vis[i][j]==-1){
                    cnt=0;
                    curr++;
                    dfs(grid,i,j);
                    mp[curr]=cnt;
                    ans=max(ans,cnt);
                }
            }
        }
        // for(auto x : mp)cout<<x.first<<" "<<x.second<<"\n";
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    set<int> nbs;
                    if(i>=1)nbs.insert(vis[i-1][j]);
                    if(i<n-1)nbs.insert(vis[i+1][j]);
                    if(j>=1)nbs.insert(vis[i][j-1]);
                    if(j<m-1)nbs.insert(vis[i][j+1]);
                    int curr=1;
                    for(auto x: nbs)curr+=mp[x];
                    ans=max(ans,curr);
                }
            }
        }
        return ans;
    }
};