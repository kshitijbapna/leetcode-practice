class Solution {
public:
    //Bellman Ford
    int networkDelayTime(vector<vector<int>>& t, int n, int k) {
        int dis[n+1];
        for(int i=0;i<=n;i++)dis[i]=INT_MAX;
        dis[k]=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<t.size();j++){
                if(dis[t[j][0]]!=INT_MAX&&dis[t[j][0]]+t[j][2]<dis[t[j][1]])
                    dis[t[j][1]]=dis[t[j][0]]+t[j][2];
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++)if(dis[i]==INT_MAX)return -1;
        else ans=max(ans,dis[i]);
        return ans;
    }
};