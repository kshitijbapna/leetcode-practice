class Solution {
public:
    int maxCoins(vector<int>& p) {
        sort(p.begin(),p.end());
        int n=p.size(),i=0,j=n-1;
        int k=0;
        while(j-1>i){
            k+=p[j-1];
            j-=2;
            i++;
        }
        return k;
    }
};