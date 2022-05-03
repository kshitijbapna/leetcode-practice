class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> x=nums;
        sort(x.begin(),x.end());
        if(nums==x)return 0;
        int n=nums.size(),i=0,j=n-1;
        while(i<n){
            if(nums[i]==x[i])i++;
            else break;
        }
        while(j>0){
            if(nums[j]==x[j])j--;
            else break;
        }
        int ans=j-i+1;
        return ans;
    }
};