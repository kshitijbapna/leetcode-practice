class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1,in=0;
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]==target){
                in=mid;
                r=mid-1;
            }
            else if(nums[mid]<target){
                in=mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        
        if(nums[in]>=target)return in;
        else return in+1;
    }
};