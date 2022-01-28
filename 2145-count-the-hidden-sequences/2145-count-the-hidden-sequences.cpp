class Solution {
public:
    int numberOfArrays(vector<int>& d, int lower, int upper) {
        int l=lower,r=upper,n=d.size(),i;
        long long int sum=0;
        // vector<long long int> pre(n);
        // pre[0]=d[0];
        // for(int i=1;i<n;i++)pre[i]=pre[i-1]+d[i];
        for(i=0;i<n;i++){
            sum+=d[i];
            long long int ll,rr;
            rr=upper-sum;
            ll=lower-sum;
            if(ll>l)l=ll;
            if(rr<r)r=rr;
        }
        if(r-l+1>0)return r-l+1;
        return 0;
    }
};