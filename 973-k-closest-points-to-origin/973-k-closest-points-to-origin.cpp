auto it=[](pair<int,int> a,pair<int,int> b){
        return a.first*a.first+a.second*a.second<b.first*b.first+b.second*b.second;
};
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& p, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(it)>pq(it);
        for(int i=0;i<p.size();i++){
            int dis=p[i][0]*p[i][0]+p[i][1]*p[i][1];
            if(pq.size()==k){
                pair<int,int> x=pq.top();
                if(x.first*x.first+x.second*x.second>dis){
                    pq.pop();
                    pq.push({p[i][0],p[i][1]});
                }
            }
            else{
                pq.push({p[i][0],p[i][1]});
            }
        }
        vector<vector<int>> ans;
        while(pq.size()){
            pair<int,int> x=pq.top();
            pq.pop();
            ans.push_back({x.first,x.second});
        }
        return ans;
    }
};