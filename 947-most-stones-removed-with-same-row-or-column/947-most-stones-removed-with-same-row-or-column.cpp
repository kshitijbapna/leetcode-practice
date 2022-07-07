class Solution {
public:
    set<pair<int,int>> vis;
    map<int,vector<int>> x,y;
    int sz=0;
    
    void dfs(int i,int j){
        vis.insert({i,j});
        sz++;
        for(auto y : x[i]){
            if(vis.find({i,y})==vis.end()){
                dfs(i,y);
            }
        }
        for(auto x : y[j]){
            if(vis.find({x,j})==vis.end()){
                dfs(x,j);
            }
        }
    }
    
    int removeStones(vector<vector<int>>& stones) {
        int ans=0;
        for(auto &stone : stones){
            x[stone[0]].push_back(stone[1]);
        }
        for(auto &stone : stones){
            y[stone[1]].push_back(stone[0]);
        }
        for(auto stone : stones){
            if(vis.find({stone[0],stone[1]})==vis.end()){
                sz=0;
                dfs(stone[0],stone[1]);
                // cout<<sz<<" ";
                ans+=sz-1;
            }
        }
        // for(auto x : vis)cout<<x.first<<" "<<x.second<<"\n";
        return ans;
    }
};