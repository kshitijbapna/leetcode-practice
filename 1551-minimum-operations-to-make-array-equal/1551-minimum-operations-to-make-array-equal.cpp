class Solution {
public:
    int minOperations(int n) {
        return ((n+1)/2)*(n-(n+1)/2);
    }
};