class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> v(nums.size());
        for(int i=0;i<nums.size();i++){
            v[i].first=nums[i];
            v[i].second=i;
        }
        int n=nums.size(),i=0,j=n-1;
        sort(v.begin(),v.end());
       
        // vector<int> ans;
        while(i<j){
            if(v[i].first+v[j].first==target){
                return {v[i].second,v[j].second};
            }
            else if(v[i].first+v[j].first>target)j--;
            else i++;
        }
        return {};
    }
};