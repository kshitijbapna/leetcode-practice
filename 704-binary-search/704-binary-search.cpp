class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;
        while(l<=r){
            int i=(l+r)/2;
            if(nums[i]==target){
                return i;
            }
            if(nums[i]<target)l=i+1;
            else r=i-1;
        }
        return -1;
    }
};