class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> c(n,1e9);
        c[src]=0;
        for(int i=0;i<=k;i++){
            vector<int> x(c);
            for(auto y : flights){
                x[y[1]]=min(x[y[1]],c[y[0]]+y[2]);
            }
            c=x;
        }
        return c[dst]==1e9?-1:c[dst];
    }
};