class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<set<int>> v(n);
        for(int i=0;i<roads.size();i++){
            v[roads[i][0]].insert(roads[i][1]);
            v[roads[i][1]].insert(roads[i][0]);
        }
        vector<int> x;
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int net_rank=v[i].size()+v[j].size();
                if(v[j].count(i))net_rank--;
                ans=max(ans,net_rank);
            }
        }
        return ans;
    }
};