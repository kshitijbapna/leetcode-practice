class Solution {
public:
    bool vis[205];
    void dfs(int st,vector<vector<int>>& is){
        vis[st]=1;
        int n=is.size();
        for(int i=0;i<n;i++){
            if(is[st][i]&&i!=st&&!vis[i]){
                dfs(i,is);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& is) {
        int k=0,n=is.size();
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,is);
                k++;
            }
        }
        return k;
    }
};