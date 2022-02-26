class Solution {
public:
    int help(vector<vector<int>> g){
        int i,n=g.size(),all=(1<<n)-1,mask=0;
        queue<pair<int,pair<int,int>>> q;
        set<pair<int,int>> s;

        for(i=0;i<n;i++){
            q.push({i,{0,1<<i}});
            s.insert({i,1<<i});
        }
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            int val=node.first,dis=node.second.first,mask=node.second.second;
            for(auto tmp : g[val]){
                int nmask=(1<<tmp)|mask;
                if(nmask==all){
                    return dis+=1;
                }else if(s.count({tmp,nmask})){
                    continue;
                }
                q.push({tmp,{dis+1,nmask}});
                s.insert({tmp,nmask});

            }
        }
        return 0;
    }
    int shortestPathLength(vector<vector<int>>& graph) {
        if(graph.size()==1)return 0;
        return help(graph);
    }
};