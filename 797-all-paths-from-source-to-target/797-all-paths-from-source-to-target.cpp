class Solution {
public:
    vector<vector<int>> ans;
    void dfs(int curr,vector<int> path,vector<vector<int>> &g){
        path.push_back(curr);
        if(curr==g.size()-1)ans.push_back(path);
        else{
            for(auto it : g[curr]){
                dfs(it,path,g);
            }
        }
        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path;
        dfs(0,path,graph);
        return ans;
    }
};