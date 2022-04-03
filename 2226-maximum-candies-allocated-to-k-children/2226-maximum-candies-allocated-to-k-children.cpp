class Solution {
public:
    bool isok(vector<int>& c,long long mi,long long k){
        if(mi==0)return 1;
        // cout<<mi<<"\n";
        long long x=0;
        for(int i=0;i<c.size();i++){
            x+=(long long)c[i]/mi;
        }
        // cout<<x<<" "<<k<<"\n";
        return x>=k;
    }
    int maximumCandies(vector<int>& c, long long k) {
        if(c.size()==1)return c[0]/k;
        long long sum=0,s2=0,n=c.size(),l=0,r,ans=0;
        for(int i=0;i<n;i++)sum+=c[i];
        sort(c.rbegin(),c.rend());
        r=1e15;
        while(l<=r){
            long long mid=(l+r)/2;
            if(isok(c,mid,k)){
                l=mid+1;
                ans=mid;
            }
            else{
                r=mid-1;
            }
        }
        
        return ans;
    }
};