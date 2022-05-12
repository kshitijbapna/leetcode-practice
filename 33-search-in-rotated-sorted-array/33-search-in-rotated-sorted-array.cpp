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
            int rmid=(mid+rot)%n;
            if(nums[rmid]==target)return rmid;
            if(nums[rmid]<target)l=mid+1;
            else r=mid-1;
        }
        return -1;
    }
};