class Solution {
public:
    int maximumWealth(vector<vector<int>>& a) {
        int ans=0;
        for(int i=0;i<a.size();i++){
            int k=0;
            for(int j=0;j<a[i].size();j++){
                k+=a[i][j];
            }
            ans=max(ans,k);
        }
        return ans;
    }
};