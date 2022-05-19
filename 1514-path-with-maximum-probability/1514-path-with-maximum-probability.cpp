class Solution {
public:
    vector<pair<double,int>> g[10005];
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        set<pair<double,int>> s;
        vector<double> v(n);
        for(int i=0;i<edges.size();i++){
            g[edges[i][0]].push_back({succProb[i],edges[i][1]});
            g[edges[i][1]].push_back({succProb[i],edges[i][0]});
        }
        for(int i=0;i<n;i++)v[i]=0;
        v[start]=-1;
        // s.insert({-1,start});
        for(int i=0;i<n;i++)s.insert({v[i],i});
        while(s.size()>0){
            auto it=s.begin();
            double pro=it->first;
            int nd=it->second;
            // cout<<pro<<" "<<nd<<"\n";
            s.erase(it);
            for(auto xx : g[nd]){
                if(v[xx.second]>xx.first*pro){
                    // cout<<xx.first*pro<<"\n";
                    s.erase(s.find({v[xx.second],xx.second}));
                    s.insert({xx.first*pro,xx.second});
                    v[xx.second]=xx.first*pro;
                }   
            }
        }
        // for(int i=0;i<n;i++)cout<<v[i]<<" ";
        return -1*v[end];
    }
};