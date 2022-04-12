class Solution {
public:
    int minOperations(int n) {
        int xx=(n+1)/2;
        return xx*(n-xx);
    }
};