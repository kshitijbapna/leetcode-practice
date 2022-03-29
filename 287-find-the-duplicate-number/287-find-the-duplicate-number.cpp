class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        bool x[nums.size()];
        memset(x,0,sizeof(x));
        for(int i=0;i<nums.size();i++){
            if(x[nums[i]]==1)return nums[i];
            x[nums[i]]=1;
        }
        return 0;
    }
};