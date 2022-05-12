class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> fin(nums1.size()+nums2.size());
        if(nums1.empty())fin=nums2;
        else if(nums2.empty())fin=nums1;
        else merge(nums1.begin(),nums1.end(),nums2.begin(),nums2.end(),fin.begin());
        int p=fin.size();
        
        if(p==1)return (float)fin[0];
        else if(p%2==0)return (fin[p/2]+fin[p/2-1])/2.0;
        else return (double)fin[p/2];
    }
};