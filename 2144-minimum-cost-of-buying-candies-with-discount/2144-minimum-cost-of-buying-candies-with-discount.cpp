class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.rbegin(),cost.rend());
        int ans=0,i;
        for(i=0;i<cost.size();i+=3){
            ans+=cost[i];
            if(i+1<cost.size())ans+=cost[i+1];
        }
        return ans;
    }
};