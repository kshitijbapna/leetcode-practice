class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int i=0,j=0,n=nums.size();
        if(n==0)return ans;
        while(1){
            j=i;
            while(j<n-1&&nums[j]==nums[j+1]-1)j++;
            if(i==j)ans.push_back(to_string(nums[i]));
            else{
                ans.push_back(to_string(nums[i])+"->"+to_string(nums[j]));
            }
            i=j+1;
            if(i>=n)break;
        }
        return ans;
    }
};