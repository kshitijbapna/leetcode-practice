class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // set<vector<int>> s;
        vector<vector<int>> ans;
        int n=nums.size();
        for(int i=0;i<(1<<n);i++){
            vector<int> x;
            int temp=i,j=0;
            while(temp){
                if(temp%2)x.push_back(nums[j]);
                j++;
                temp/=2;
            }
            ans.push_back(x);
        }
        return ans;
    }
};