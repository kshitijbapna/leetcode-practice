class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        vector<int> a(101);
        int ans=0,m=1e9+7;
        for(int i=0;i<arr.size();i++)
            a[arr[i]]++;
        for(int i=0;i<101;i++){
            for(int j=0;j<=i;j++){
                if(!(a[i]>0&&a[j]>0))continue;
                int k=target-i-j;
                if(k<i||k>100)continue;
                long long y;
                if(i==j&&j==k){
                    y=(long long)a[i]*(a[i]-1)*(a[i]-2)/6;
                    y%=m;
                    ans+=y;
                }
                else if(j==i){
                    y=(long long)a[k]*a[i]*(a[i]-1)/2;y%=m;
                    ans+=y;
                }
                else if(k==i){
                    y=(long long)a[j]*a[i]*(a[i]-1)/2;y%=m;
                    ans+=y;
                }
                else{
                    y=(long long)a[i]*a[j]*a[k];y%=m;
                    ans+=y;
                }
                // cout<<i<<" "<<j<<" "<<k<<" "<<y<<"\n";
                ans%=m;
            }
        }
        return ans;
    }
};