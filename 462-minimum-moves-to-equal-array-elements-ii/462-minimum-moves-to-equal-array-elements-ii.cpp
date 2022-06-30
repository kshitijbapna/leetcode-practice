class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        long long int n=nums.size(),sum1=0,sum2=0,ans=0;
        for(int i=1;i<n;i++){
            sum2+=nums[i];
        }
        ans=sum2-(n-1)*nums[0];
        for(int i=1;i<n;i++){
            if(i==n-1){
                sum1+=nums[i-1];
                long long int tmp=(long long int)(n-1)*nums[i]-sum1;
                ans=min(tmp,ans);
                continue;
            }
            sum1+=nums[i-1];
            sum2-=nums[i];
            long long int tmp=sum2-((long long int)n-i-1)*nums[i]+(long long int)i*nums[i]-sum1;
            ans=min(ans,tmp);
        }
        return ans;
    }
};