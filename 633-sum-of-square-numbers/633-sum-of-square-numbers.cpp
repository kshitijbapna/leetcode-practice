class Solution {
public:
    bool judgeSquareSum(int c) {
        for(long long i=0;i<100000;i++){
            long long y=c-i*i;
            if(y<0)return 0;
            long long xx=sqrt(y);
            if(xx*xx==y)return 1;
        }
        return 0;
    }
};