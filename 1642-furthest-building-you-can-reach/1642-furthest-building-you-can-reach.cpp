class Solution {
public:
    int furthestBuilding(vector<int>& v, int bricks, int ladders) {
        priority_queue<int> pq;
        int n=v.size(),i;
        for(i=0;i<n-1;i++){
            if(v[i]<v[i+1]){
                if(bricks>=v[i+1]-v[i]){
                    bricks-=(v[i+1]-v[i]);
                    pq.push(v[i+1]-v[i]);
                }
                else if(ladders>0&&(pq.size()==0||pq.top()<v[i+1]-v[i])){
                    ladders--;
                }
                else if(ladders>0&&pq.size()>0){
                    while(ladders>0&&pq.size()>0){
                        ladders--;
                        bricks+=pq.top();
                        pq.pop();
                        if(bricks>=v[i+1]-v[i])break;
                    }
                    if(bricks>=v[i+1]-v[i]){
                        bricks-=(v[i+1]-v[i]);
                        pq.push(v[i+1]-v[i]);
                    }
                    else break;
                }
                else break;
                // cout<<v[i+1]-v[i]<<" "<<bricks<<" "<<ladders<<" "<<i<<" "<<pq.size()<<"\n";
            }
            else continue;
        }
        return i;
    }
};