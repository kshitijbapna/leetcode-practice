class Solution {
public:
    vector<int> adj[2005];
    vector<int> findOrder(int numCourses, vector<vector<int>>& p) {
        vector<int> vis(2005);
        for(int i=0;i<p.size();i++){
            adj[p[i][0]].push_back(p[i][1]);
        }
        queue<int> q;
        vector<int> inc(numCourses);
        for(int i=0;i<numCourses;i++){
            for(auto x : adj[i]){
                inc[x]++;
            }
        }
        for(int i=0;i<numCourses;i++){
            if(inc[i]==0){
                q.push(i);
            }
        }
        bool f=1;
        vector<int> ans;
        while(!q.empty()){
            int x=q.front();
            q.pop();
            vis[x]=1;
            ans.push_back(x);
            for(auto node : adj[x]){
                inc[node]--;
                if(!vis[node]&&inc[node]==0){
                    q.push(node);
                }
            }
        }
        for(int i=0;i<numCourses;i++){
            if(vis[i]==0)f=0;
        }
        if(f==0)return {};
        reverse(ans.begin(),ans.end());
        return ans;
    }
};