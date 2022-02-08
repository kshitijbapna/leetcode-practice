class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int tot=(1<<nums.size());
        set<vector<int>> s;
        for(int i=0;i<tot;i++){
            vector<int> x;
            for(int j=0;j<nums.size();j++){
                if(1&(i>>j))x.push_back(nums[j]);
            }
            sort(x.begin(),x.end());
            s.insert(x);
        }
        vector<vector<int>> ans;
        for(auto x: s)ans.push_back(x);
        return ans;
    }
};