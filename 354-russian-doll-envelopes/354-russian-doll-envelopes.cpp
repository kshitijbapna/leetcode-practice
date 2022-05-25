class Solution {
public:
    static bool cmp(vector<int> a,vector<int> b){
        if(a[0]==b[0])return a[1]>b[1];
        return a[0]<b[0];
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res;
        for(int i=0; i<nums.size(); i++) {
            auto it = std::lower_bound(res.begin(), res.end(), nums[i]);
            if(it==res.end()) res.push_back(nums[i]);
            else *it = nums[i];
        }
        return res.size();
    }
    int maxEnvelopes(vector<vector<int>>& e) {
        vector<int> x;
        sort(e.begin(),e.end(),cmp);
        for(int i=0;i<e.size();i++)x.push_back(e[i][1]);
        return lengthOfLIS(x);
    }
};