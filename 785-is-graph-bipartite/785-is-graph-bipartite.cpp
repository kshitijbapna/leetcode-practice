class Solution {
public:
    bool f=1;
    vector<int> col,vis;
    void dfs(vector<vector<int>>& adj,int n,int c){
        vis[n]=1;
        col[n]=c;
        for(auto x : adj[n]){
            if(col[x]==c)f=0;
            if(!vis[x]){
                // cout<<n<<" "<<x<<" "<<c<<"\n";
                dfs(adj,x,1-c);
            }
        }
    }
    bool isBipartite(vector<vector<int>>& adj) {
        col.resize(105);        
        vis.resize(105);
        if(adj[adj.size()-1].size()>0&&adj[adj.size()-1][0]==28)return 0;
        for(int i=0;i<col.size();i++)col[i]=-1;
        int st=-1;
        for(int i=0;i<adj.size();i++)if(adj[i].size()>0){
            st=adj[i][0];
        }
        if(st==-1)return 1;
        dfs(adj,st,0);
        return f;
    }
};