class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0,j=0;
        if(m==0){
            nums1=nums2;
            return;
        }

        for(int i=m;i<nums1.size();i++){
            if(nums1[i]==0){
                nums1.erase(nums1.begin()+i);i--;
            }
        }
        for(int i=0;i<nums2.size();i++){
            auto it=lower_bound(nums1.begin(),nums1.end(),nums2[i]);
            nums1.insert(it,nums2[i]);
        }
        
    }
};