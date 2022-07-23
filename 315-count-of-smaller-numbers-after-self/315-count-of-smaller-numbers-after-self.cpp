#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds;
typedef tree<long long, null_type, less_equal<>, rb_tree_tag, tree_order_statistics_node_update> indexed_multiset;
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        indexed_multiset s;
        for(int i=0;i<nums.size();i++)s.insert(nums[i]);
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            s.erase(s.find_by_order(s.order_of_key(nums[i])));
            ans.push_back(s.order_of_key(nums[i]));
        }
        // s.erase(s.find_by_order(5));
        // for(auto x : s)cout<<x<<" ";
        return ans;
    }
};