class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int ans=0;
        for(int i=0;i<nums1.size();i++){
            int in=-1,l=i,r=nums2.size()-1;
            while(l<=r){
                int mid=(l+r)/2;
                if(nums2[mid]>=nums1[i]){
                    in=mid;
                    l=mid+1;
                }
                else{
                    r=mid-1;
                }
            }
            if(in!=-1){
                ans=max(ans,in-i);
            }
        }
        return ans;
    }
};