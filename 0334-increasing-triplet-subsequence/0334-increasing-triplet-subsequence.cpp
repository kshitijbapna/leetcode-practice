class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        multiset<int> s1,s2;
        s1.insert(-nums[0]);
        for(int i=2;i<nums.size();i++){
            s2.insert(nums[i]);
        }
        for(int i=1;i<nums.size()-1;i++){
            if(s1.upper_bound(-nums[i])!=s1.end()&&s2.upper_bound(nums[i])!=s2.end())return 1;
            s1.insert(-nums[i]);
            s2.erase(s2.find(nums[i+1]));
        }
        return 0;
    }
};
// x c1 c2
// 2  2  +
// 1  1  +
// 5  1  5
// 0  0  5
// 4  0  4


