class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& in) {
        vector<vector<int>> ans;
        sort(in.begin(),in.end());
        int i=0,n=in.size();
        while(i<n){
            int st=in[i][0],en=in[i][1];
            while(i+1<n&&en>=in[i+1][0]){
                en=max(en,in[i+1][1]);
                i++;
            }
            ans.push_back({st,en});
            i++;
        }
        return ans;
    }
};