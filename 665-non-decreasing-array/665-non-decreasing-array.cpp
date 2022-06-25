class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int cnt=0,prev=INT_MIN;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]<=nums[i+1]){
                prev=nums[i];
            }
            else{
                if(nums[i+1]<prev){
                    nums[i+1]=nums[i];
                }
                cnt+=1;
            }
        }
        return cnt<=1;
    }
};