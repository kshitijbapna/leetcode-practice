class Solution {
public:
    int brokenCalc(int ss, int tt) {
        int ans=0;
        while(tt>ss){
            if(tt%2)tt++;
            else tt/=2;
            ans++;
        }
        ans+=ss-tt;
        return ans;
    }
};