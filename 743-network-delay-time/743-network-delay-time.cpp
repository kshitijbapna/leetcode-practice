class Solution {
public:
    //Bellman Ford
    // int networkDelayTime(vector<vector<int>>& t, int n, int k) {
    //     int dis[n+1];
    //     for(int i=0;i<=n;i++)dis[i]=INT_MAX;
    //     dis[k]=0;
    //     for(int i=0;i<n;i++){
    //         for(int j=0;j<t.size();j++){
    //             if(dis[t[j][0]]!=INT_MAX&&dis[t[j][0]]+t[j][2]<dis[t[j][1]])
    //                 dis[t[j][1]]=dis[t[j][0]]+t[j][2];
    //         }
    //     }
    //     int ans=0;
    //     for(int i=1;i<=n;i++)if(dis[i]==INT_MAX)return -1;
    //     else ans=max(ans,dis[i]);
    //     return ans;
    // }
    
    
    //dij
    vector<pair<int,int>> g[105];
    int networkDelayTime(vector<vector<int>>& t, int n, int k) {
        int dis[n+1];
        for(int i=0;i<=n;i++)dis[i]=1e6;
        dis[k]=0;
        for(int i=0;i<t.size();i++){
            g[t[i][0]].push_back({t[i][2],t[i][1]});
        }
        set<pair<int,int>> s;
        for(int i=1;i<=n;i++)s.insert({dis[i],i});
        while(s.size()>0){
            int cd=s.begin()->first;
            int cn=s.begin()->second;
            s.erase(s.begin());
            for(auto x : g[cn]){
                if(cd+x.first<dis[x.second]){
                    s.erase(s.find({dis[x.second],x.second}));
                    s.insert({cd+x.first,x.second});
                    dis[x.second]=cd+x.first;
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++)if(dis[i]==1e6)return -1;
        else ans=max(ans,dis[i]);
        return ans;
    }
};