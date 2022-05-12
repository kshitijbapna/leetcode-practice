class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l=0,r=nums.size()-1,ans=nums[nums.size()-1];
        while(l<r){
            int mid=(l+r)/2;
            if(mid%2){
                if(nums[mid]!=nums[mid-1]){
                    r=mid;
                    ans=nums[mid];
                }
                else{
                    l=mid+1;
                }
            }
            else{
                if(nums[mid]!=nums[mid+1]){
                    r=mid;
                    ans=nums[mid];
                }
                else{
                    l=mid+1;
                }
            }
        }
        return ans;
    }
};