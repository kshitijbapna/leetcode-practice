class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i+=2){
            for(int j=i+2;j<n;j+=2){
                if(nums[i]>nums[j])swap(nums[i],nums[j]);
            }
        }
        for(int i=1;i<n;i+=2){
            for(int j=i+2;j<n;j+=2){
                if(nums[i]<nums[j])swap(nums[i],nums[j]);
            }
        }
        return nums;
    }
};