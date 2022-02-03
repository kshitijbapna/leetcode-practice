class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int ans=0;
        // sort(nums4.begin(),nums4.end());
        int n=nums1.size();
        map<int,int> m;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                m[nums1[i]+nums2[j]]++;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                // m[nums1[i]+nums2[j]]++;
                auto it=m.find(-1*(nums3[i]+nums4[j]));
                if(it!=m.end()){
                    ans+=(*it).second;
                }
            }
        }               
        return ans;
    }
};