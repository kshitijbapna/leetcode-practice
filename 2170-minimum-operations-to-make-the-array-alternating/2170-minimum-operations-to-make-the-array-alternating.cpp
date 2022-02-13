class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int o[100005],e[100005];
        memset(o,0,sizeof(o));
        memset(e,0,sizeof(e));

        int n=nums.size();
        for(int i=0;i<n;i++){
            if(i%2)o[nums[i]]++;
            else e[nums[i]]++;
        }
        
        int m1=0,in1=0,m2=0,in2=0,sm1=0,sin1=0,sm2=0,sin2=0;
        
        for(int i=0;i<100005;i++){
            if(e[i]>=m1){
                m1=e[i];
                in1=i;
            }
            if(o[i]>m2){
                m2=o[i];
                in2=i;
            }
        }
        
        for(int i=0;i<100005;i++){
            if(e[i]>sm1&&e[i]<m1){
                sm1=e[i];
                sin1=i;
            }
            if(o[i]>sm2&&o[i]<m2){
                sm2=o[i];
                sin2=i;
            }
        }
        // cout<<in1<<" "<<in2<<"\n";
        // cout<<m1<<" "<<m2<<"\n";
        // cout<<sin1<<" "<<sin2<<"\n";
        // cout<<sm1<<" "<<sm2<<"\n";

        if(in1==in2){
            return n-max(sm1+m2,sm2+m1);
        }
        
        return n-m1-m2;
        
    }
};