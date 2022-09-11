class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<pair<int,int>> se;
        for(int i=0;i<n;i++){
            se.push_back({speed[i],efficiency[i]});
        }
        sort(se.rbegin(),se.rend());
        long long t_s=0,m=1e9+7,mx=0;
        for(int i=0;i<n;i++){
            if(pq.size()<k){
                pq.push({se[i].second,se[i].first});
                t_s+=se[i].first;
                long long mn=pq.top().first;
                mx=max(mx,mn*t_s);
            }
            else{
                pq.push({se[i].second,se[i].first});
                pair<int,int> tp=pq.top();
                pq.pop();
                t_s-=tp.second;
                t_s+=se[i].first;
                long long mn=pq.top().first;
                mx=max(mx,mn*t_s);
            }
        }
        while(pq.size()>0){
            pair<int,int> tp=pq.top();
            pq.pop();
            t_s-=tp.second;
            // t_s+=se[i].first;
            long long mn=pq.top().first;
            mx=max(mx,mn*t_s);
        }
        return mx%m;
    }
};