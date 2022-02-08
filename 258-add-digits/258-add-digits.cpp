class Solution {
public:
    int addDigits(int num) {
        if(num==0)return 0;
        int ans=0,prev=0;
        while(1){
            ans=0;
            while(num>0){
                ans+=num%10;
                num/=10;
            }
            num=ans;
            if(num/10==0)break;
        }
        return num;
    }
};