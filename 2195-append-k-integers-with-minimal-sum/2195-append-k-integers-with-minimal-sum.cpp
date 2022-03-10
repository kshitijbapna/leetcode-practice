class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        nums.push_back(0);
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)cout<<nums[i]<<" ";
        long long ans=0,n=nums.size();
        for(int i=0;i<n-1;i++){
            int st=nums[i]+1,en=nums[i+1]-1;
            int l=en-st+1;
            // 1 2 3 4
            // cout<<st<<" "<<en<<" ";
            l=min(l,k);
            if(l>0)
            {ans+=(long long)l*(l-1)/2+(long long)l*st;
            // cout<<ans<<"\n";
            k-=l;}
            if(k<=0)break;
        }
        // cout<<k<<" ";
        long long en=nums[n-1]+1;
        ans+=(long long)k*(k-1)/2+k*en;
        return ans;
    }
};