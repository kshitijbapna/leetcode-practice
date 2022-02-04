class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size(),ans=0,sum=0;
        map<int,int> m;
        for(int i=0;i<n;i++){
            if(nums[i]==0)sum--;
            else sum++;
            if(sum==0)ans=max(ans,i+1);
            if(m.find(sum)==m.end()){
                m[sum]=i;
            }
            else{
                ans=max(ans,i-m[sum]);
            }
        }
        return ans;
    }
};