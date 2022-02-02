class Solution {
public:
    double help(double x,long long int n){
        if(n==0)return 1;
        if(n%2==1){
            return help(x,n/2)*help(x,n/2)*x;
        }
        else{
            return help(x,n/2)*help(x,n/2);
        }
    }
    double myPow(double x, int n) {
        if(x==1)return 1;
        if(x==-1){
            if(n%2==0)return 1;
            else return -1;
        }
        long long int nn=n;
        if(n<0){
            nn=abs((long long int)n);
            x=1/x;
        }
        if(x>0&&x<1&&nn>1000000)return 0;
        return help(x,nn);
    }
};