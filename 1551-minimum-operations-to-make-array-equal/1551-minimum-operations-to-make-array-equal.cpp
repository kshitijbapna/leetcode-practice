class Solution {
public:
    int minOperations(int n) {
        // 1 3 5 7 9       
        // 1 3 5 7 9 11
        // 1 3 5 7 9 11 13 
        int i=1,ans=0;
        while(i<n){
            ans+=n-i;
            i+=2;
        }
        return ans;
    }
};