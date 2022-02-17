class Solution {
public:
    vector<vector<int>> ans;
    void help(int i,vector<int> candidates,int target,vector<int> &comb){
        if(target==0){
            ans.push_back(comb);
            return;
        }
        if(i==candidates.size()){
            return;
        }
        if(candidates[i]<=target){
            comb.push_back(candidates[i]);
            help(i,candidates,target-candidates[i],comb);
            comb.pop_back();
        }
        help(i+1,candidates,target,comb);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> comb;
        help(0,candidates,target,comb);
        return ans;
    }
};