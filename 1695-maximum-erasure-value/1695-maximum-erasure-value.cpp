class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        set<int> s;
        int ans=0,l=0,r=0,n=nums.size(),sum=0;
        while(r<n){
            if(s.find(nums[r])==s.end()){
                sum+=nums[r];
                s.insert(nums[r]);
                ans=max(ans,sum);
                r++;
            }else{
                while(l<r){
                    s.erase(nums[l]);
                    sum-=nums[l];
                    l++;
                    if(nums[l-1]==nums[r])break;
                }
            }
        }
        return ans;
    }
};