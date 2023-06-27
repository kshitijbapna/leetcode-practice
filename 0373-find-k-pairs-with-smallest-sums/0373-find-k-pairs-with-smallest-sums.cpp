class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int,pair<int,int>>> pq;
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                int x=(nums1[i]+nums2[j]);
                if(pq.size()<k){
                    pq.push({x,{nums1[i],nums2[j]}});
                }
                else if(pq.top().first>x){
                    pq.pop();
                    pq.push({x,{nums1[i],nums2[j]}});
                }
                else break;
            }
        }
        vector<vector<int>> res;
        while(!pq.empty()){
            pair<int,int> p=pq.top().second;
            res.push_back({p.first,p.second});
            // cout<<p.first<<" "<<p.second<<"\n";
            pq.pop();
        }
        return res;
    }
};