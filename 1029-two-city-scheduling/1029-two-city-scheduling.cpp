class Solution {
public:
    static bool cmp(vector<int> a,vector<int> b){
        return a[1]-a[0]<b[1]-b[0];
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int N = costs.size()/2;
        int minCost = 0;
        for(vector<int> cost : costs){
            minCost += cost[0];
        }
        sort(costs.begin(), costs.end(),cmp);
        for(int i = 0;i<N; i++){
            minCost += costs[i][1]-costs[i][0];
        }
        return minCost;
    }
};