class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1)return 0;
        int n=nums.size();
        if(nums[0]>nums[1])return 0;
        if(nums[n-1]>nums[n-2])return n-1;
        int l=1,r=n-2;
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]>nums[mid-1]&&nums[mid]>nums[mid+1])return mid;
            else if(nums[mid]<nums[mid-1])r=mid-1;
            else if(nums[mid]<nums[mid+1])l=mid+1;
        }
        return -1;
    }
};