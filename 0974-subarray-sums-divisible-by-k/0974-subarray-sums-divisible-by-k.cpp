class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        for(int i=0;i<nums.size();i++)
            nums[i]%=k;
        map<int,int> m;
        m[0]=1;
        int ans=0,sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            int rem=sum%k;
            if(rem<0)rem+=k;
            ans+=m[rem];
            m[rem]++;
        }
        return ans;
    }
};