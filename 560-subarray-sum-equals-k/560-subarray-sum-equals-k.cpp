class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size(),ans=0,sum=0;
        map<int,int> m;
        m[0]++;
        for(auto x : nums){
            sum+=x;
            ans+=(m[sum-k]);
            m[sum]++;
        }
        return ans;
    }
};