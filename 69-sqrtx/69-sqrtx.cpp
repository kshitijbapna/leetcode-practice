class Solution {
public:
    int mySqrt(int x) {
        long long int l=1,r=66666;
        if(x==0)return 0;
        int k=50;
        while(l<r){
            k--;
            if(k==0)break;
            long long int mid=(l+r)/2;
            if(mid*mid>x){
                r=mid;
            }
            else if(mid*mid<x){
                l=mid;
            }
            else return (int)mid;
            // cout<<l<<" "<<r<<"\n";
            if(l==r||l==r+1)break;
        }
        return l;
    }
};