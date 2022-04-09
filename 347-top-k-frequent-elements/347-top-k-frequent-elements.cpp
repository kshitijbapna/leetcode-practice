auto it=[](pair<int,int> a,pair<int,int> b){
        return a.first>b.first;
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(it)> pq(it);
        map<int,int> m;
        for(auto x : nums)m[x]++;
        for(auto x : m){
            // cout<<x.first<<" "<<x.second<<"\n";
            if(pq.size()<k)pq.push({x.second,x.first});
            else if(pq.top().first<x.second){
                pq.pop();
                // cout<<x.second<<" "<<x.first<<"\n";
                pq.push({x.second,x.first});
            }
            // cout<<pq.top().first<<" "<<pq.top().second<<" "<<pq.size()<<"\n";
        }
        vector<int> ans;
        while(pq.size()>0){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};