class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        set<vector<int>> s;
        for(int i=0;i<n;i++){
            int l=0,r=n-1;
            while(l<r&&l<n&&r>-1){
                if(l==i){
                    l++;
                    continue;
                }
                if(r==i){
                    r--;
                    continue;
                }
                int x=nums[l]+nums[r]+nums[i];
                if(!x){
                    vector<int> xx{nums[i],nums[l],nums[r]};
                    sort(xx.begin(),xx.end());
                    s.insert(xx);
                    while (l<n-1&&nums[l]==nums[l+1]) l++;
                    while (r>=1&&nums[r]==nums[r-1]) r--;
                    l++;
                    r--;
                }
                else if(x<0){
                    l++;
                }
                else{
                    r--;
                }
            }
        }
        for(auto x : s)ans.push_back(x);
        return ans;
    }
};