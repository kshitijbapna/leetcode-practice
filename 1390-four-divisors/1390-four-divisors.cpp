class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            int div=0,sum=0;
            for(int j=1;j<=sqrt(nums[i]);j++){
                if(nums[i]%j==0){
                    if(nums[i]/j!=j){
                        div+=2;
                        sum+=nums[i]/j;
                        sum+=j;
                    }
                    else{
                        div+=1;
                    }
                    if(div>4)break;
                }
            }
            if(div==4)ans+=sum;
        }
        return ans;
    }
};