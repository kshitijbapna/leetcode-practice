class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& ma) {
        vector<vector<int>> ans(2);
        vector<int> winn(100005);
        vector<int> loss(100005);
        for(int i=0;i<ma.size();i++){
            winn[ma[i][0]]++;
            loss[ma[i][1]]++;
        }
        for(int i=0;i<100005;i++){
            if(loss[i]==0&&winn[i]>0)ans[0].push_back(i);
            if(loss[i]==1)ans[1].push_back(i);
        }
        return ans;
    }
};