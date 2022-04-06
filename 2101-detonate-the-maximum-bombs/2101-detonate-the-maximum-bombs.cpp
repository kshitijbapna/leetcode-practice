class Solution {
public:
    vector<int> adj[105];
    void dfs(int n,int &c,int *vis){
        vis[n]=1;
        c++;
        for(auto x : adj[n]){
            if(!vis[x])dfs(x,c,vis);
        }
    }
    int maximumDetonation(vector<vector<int>>& b) {
        int n=b.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j&&(long long)b[i][2]*b[i][2]>=(long long)(b[j][1]-b[i][1])*(b[j][1]-b[i][1])+(long long)(b[j][0]-b[i][0])*(b[j][0]-b[i][0])){
                    adj[i].push_back(j);
                }
            }
        }
        vector<int> cnt(105,1);
        for(int i=0;i<101;i++){
            int c=0,vis[105];
            memset(vis,0,sizeof(vis));
            dfs(i,c,vis);
            cnt[i]=c;
        }
        return *max_element(cnt.begin(),cnt.end());
    }
};