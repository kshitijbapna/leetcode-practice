class Solution {
public:
    set<vector<int>> s;
    vector<vector<int>> ans;
    void solve(vector<int> &nums,vector<int> curr,int i){
        if(i<0){
            if(s.count(curr)==0){
                ans.push_back(curr);
                s.insert(curr);
            }
            return;
        }
        solve(nums,curr,i-1);
        curr.push_back(nums[i]);
        solve(nums,curr,i-1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> curr;
        sort(nums.rbegin(),nums.rend());
        solve(nums,curr,nums.size()-1);
        return ans;
    }
};