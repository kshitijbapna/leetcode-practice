class Solution {
public:
    int concatenatedBinary(int n) {
        
        long long ans=0;
        long long k=1;
        for(int i=n;i>=1;i--){
            int tmp=i;
            while(tmp>0){
                if(tmp%2==1)ans+=k;
                tmp/=2;
                ans%=(int)(1e9+7);
                k*=2;
                k%=(int)(1e9+7);
            }
        }
        return ans;
    }
};