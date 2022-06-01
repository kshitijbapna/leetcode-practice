class Solution {
public:
    vector<pair<int,int>> g[100005];
    bool vis[100005];
    int ans=0;
    void dfs(int i,int sum){
        vis[i]=1;
        ans=max(ans,sum);
        for(auto x : g[i]){
            if(!vis[x.first]){
                dfs(x.first,sum+x.second);
            }
        }
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        for(int i=0;i<manager.size();i++){
            if(manager[i]!=-1){
                g[manager[i]].push_back({i,informTime[i]});
            }
        }
        dfs(headID,informTime[headID]);
        return ans;
    }
};