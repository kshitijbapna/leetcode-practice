class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,1);
        long long int l=1;
        for(int i=1;i<n;i++){
            l*=nums[i-1];
            ans[i]*=l;
        }
        l=1;
        for(int i=n-2;i>=0;i--){
            l*=nums[i+1];
            ans[i]*=l;
        }
        return ans;
    }
};