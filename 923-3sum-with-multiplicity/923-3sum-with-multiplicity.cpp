class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        vector<long long> a(101);
        int ans=0,m=1e9+7;
        for(int i=0;i<arr.size();i++)a[arr[i]]++;
        for(int i=0;i<101;i++){
            for(int j=0;j<=i;j++){
                int k=target-i-j;
                if(!(a[i]>0&&a[j]>0)||k<i||k>100)continue;
                long long y;
                if(i==j&&j==k)  y=a[i]*(a[i]-1)*(a[i]-2)/6;
                else if(j==i)   y=a[k]*a[i]*(a[i]-1)/2;
                else if(k==i)   y=a[j]*a[i]*(a[i]-1)/2;
                else            y=a[i]*a[j]*a[k];
                ans+=y%m;
                ans%=m;
            }
        }
        return ans;
    }
};