class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        vector<int> b1(32),b2(32);
        for(int i=0;i<arr1.size();i++){
            int x=0;
            while(arr1[i]>0){
                if(arr1[i]%2)b1[x]++;
                x++;
                arr1[i]/=2;
            }
        }
        for(int i=0;i<arr2.size();i++){
            int x=0;
            while(arr2[i]>0){
                if(arr2[i]%2)b2[x]++;
                x++;
                arr2[i]/=2;
            }
        }
        int ans=0;
        for(int i=0;i<32;i++){
            if(((long long)b1[i]*b2[i])%2){
                ans+=(1ll<<i);
            }
        }
        return ans;
    }
};