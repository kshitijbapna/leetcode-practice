class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        long long l=min(a,b),r=(long long)min(a,b)*n,ans;
        while(l<=r){
            long long mid=(l+r)/2;
            if(mid/a+mid/b-(mid*__gcd(a,b))/(a*b)<n)l=mid+1;
            else{
                ans=mid;
                r=mid-1;
            }
        }
        return ans%(int)(1e9+7);
    }
};