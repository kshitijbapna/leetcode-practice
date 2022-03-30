class Solution {
public:
    bool vis[305][305];
    void dfs(int i,int j,vector<vector<char>>& g){
        if(i<0||j<0||i>g.size()-1||j>g[0].size()-1)return;
        if(g[i][j]=='0')return;
        if(vis[i][j]==1)return;
        vis[i][j]=1;
        dfs(i-1,j,g);
        dfs(i,j+1,g);
        dfs(i+1,j,g);
        dfs(i,j-1,g);
    }
    int numIslands(vector<vector<char>>& g) {
        int ans=0;
        for(int i=0;i<g.size();i++){
            for(int j=0;j<g[0].size();j++){
                if(g[i][j]=='1'&&vis[i][j]==0){
                    ans++;
                    dfs(i,j,g);
                }
            }
        }
        return ans;
    }
};