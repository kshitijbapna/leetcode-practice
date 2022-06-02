class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> a(1001),ans;
        for(int i=0;i<nums1.size();i++)a[nums1[i]]++;
        for(int i=0;i<nums2.size();i++){
            if(a[nums2[i]]>0){
                ans.push_back(nums2[i]);
                a[nums2[i]]--;
            }
        }
        return ans;
    }
};