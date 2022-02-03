class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        set<vector<int>> s;
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-3;i++){
            for(int j=i+1;j<n-2;j++){
                for(int k=j+1;k<n-1;k++){
                    long long int x=(long long int)target-nums[i]-nums[j]-nums[k];
                    int in=upper_bound(nums.begin(),nums.end(),x)-nums.begin();
                    in--;
                    if(in<n&&in>k&&nums[in]==x){
                        vector<int> y{nums[i],nums[j],nums[k],(int)x};
                        if(s.count(y)==0)ans.push_back(y);
                        s.insert(y);
                    }
                }
            }
        }
        return ans;
    }
};