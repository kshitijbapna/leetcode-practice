class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& in) {
        vector<vector<int>> ans;
        sort(in.begin(),in.end());
        bool done[in.size()];
        memset(done,0,sizeof(done));
        for(int i=0;i<in.size();i++){
            if(done[i]==0){
                int st=in[i][0],en=in[i][1],j=i+1;
                while(j<in.size()&&en>=in[j][0]){
                    en=max(en,in[j][1]);
                    done[j]=1;
                    j++;
                }
                ans.push_back({st,en});
            }
        }
        return ans;
    }
};