class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ans=1e6;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int sum=nums[i]+nums[j];
                int in1=lower_bound(nums.begin(),nums.end(),target-sum)-nums.begin();
                for(int k=max(in1-2,0);k<min(n,in1+3);k++){
                    if(k!=i&&k!=j&&abs(sum+nums[k]-target)<abs(target-ans)){
                        ans=sum+nums[k];
                    }
                }
            }
        }
        return ans;
    }
};