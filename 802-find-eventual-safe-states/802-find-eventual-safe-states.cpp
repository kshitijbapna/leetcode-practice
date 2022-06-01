class Solution {
public:
    bool dfs(vector<vector<int>>& g,int i,vector<int> &color){
        color[i]=1;
        for(auto cur : g[i])
            if((color[cur]==0&&dfs(g,cur,color))||color[cur]==1)
                return 1;
        color[i]=2;
        return 0;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& g) {
        vector<int> color(g.size()),res;
        for(int i=0;i<g.size();i++){
            if(color[i]==2||!dfs(g,i,color))
                res.push_back(i);
        }
        return res;
    }
};