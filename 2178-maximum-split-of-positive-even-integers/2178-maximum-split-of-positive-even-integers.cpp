class Solution {
public:
    vector<long long> maximumEvenSplit(long long f) {
        vector<long long> ans;
        if(f%2)return ans;
        long long j,i=0,y=f/2;
        for(i=0;i<100005;i++){
            if(i*(i+1)>=f)break;
        }
        if(i*(i+1)==f){
            for(j=1;j<=i;j++)ans.push_back(j*2);
        }
        else{
            for(j=1;j<i;j++){
                ans.push_back(j*2);
                f-=j*2;
            }
            if(f<=ans[ans.size()-1])ans[ans.size()-1]+=f;
            else ans.push_back(f);
        }
        return ans;
    }
};