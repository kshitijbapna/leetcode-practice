class Solution {
public:
    int stoneGameVI(vector<int>& a, vector<int>& b) {
        priority_queue<pair<int,pair<int,int>>> pq;
        int n=a.size();
        for(int i=0;i<n;i++){
            pq.push({a[i]+b[i],{a[i],b[i]}});
        }
        int ap=0,bp=0;
        for(int i=0;i<n;i++){
            if(i%2==0){
                ap+=pq.top().second.first;
                pq.pop();
            }
            else{
                bp+=pq.top().second.second;
                pq.pop();
            }
        }
        if(ap>bp)return 1;
        else if(ap==bp)return 0;
        return -1;
    }
};