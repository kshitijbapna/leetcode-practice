class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size(),l=0,r=n-1;
        while(l<r){
            int mid=(l+r)/2;
            if(nums[mid]>nums[r]){
                l=mid+1;
            }
            else{
                r=mid;
            }
        }
        int rot=l;
        l=0,r=n-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[(mid+rot)%n]==target)return (mid+rot)%n;
            else if(nums[(mid+rot)%n]<target){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return -1;
    }
};