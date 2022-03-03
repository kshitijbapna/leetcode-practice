class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& v) {
        if(v.size()<3)return 0;
        int n=v.size(),ans=0;
        for(int i=0;i<n-1;i++){
            int d=v[i+1]-v[i];
            for(int j=i+2;j<n;j++){
                if(v[j]==v[j-1]+d){
                    // cout<<i<<" "<<j<<"\n";
                    ans++;
                }
                else break;
            }
        }
        return ans;
    }
};