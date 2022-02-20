class Solution {
public:
    int a[100005],fre[100005],cnt[100005];
    long long coutPairs(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> div;
        long long res=0;
        for(int i=0;i<n;i++){
            a[i]=__gcd(nums[i],k);
            fre[a[i]]++;
        }
        for(int i=1;i<=k;i++)if(k%i==0)div.push_back(i);
        for(auto i: div){
            int c=0;
            for(int j=i;j<100005;j+=i)c+=fre[j];
            cnt[i]=c;
        }
        for(int i=0;i<n;i++){
            res+=1LL*cnt[k/a[i]];
            if(a[i]%(k/a[i])==0)res--;
        }
        res/=2;
        return res;
    }
};