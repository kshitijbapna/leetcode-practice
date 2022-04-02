class Solution {
public:
    bool canMeasureWater(int j1, int j2, int t) {
        if(t>j1+j2)return 0;
        if(t%__gcd(j1,j2)==0)return 1;
        return 0;
    }
};