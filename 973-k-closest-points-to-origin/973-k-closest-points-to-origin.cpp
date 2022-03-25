class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& p, int k) {
        priority_queue<pair<int,pair<int,int>>> pq;
        for(int i=0;i<p.size();i++){
            int dis=p[i][0]*p[i][0]+p[i][1]*p[i][1];
            if(pq.size()==k){
                pair<int,pair<int,int>> x=pq.top();
                if(x.first>dis){
                    pq.pop();
                    pq.push({dis,{p[i][0],p[i][1]}});
                }
            }
            else{
                pq.push({dis,{p[i][0],p[i][1]}});
            }
        }
        vector<vector<int>> ans;
        while(pq.size()){
            pair<int,pair<int,int>> x=pq.top();
            pq.pop();
            ans.push_back({x.second.first,x.second.second});
        }
        return ans;
    }
};