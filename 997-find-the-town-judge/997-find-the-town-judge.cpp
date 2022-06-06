class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        map<int,set<int>> x;
        for(int i=0;i<trust.size();i++){
            x[trust[i][1]].insert(trust[i][0]);
        }
        vector<int> y;
        for(int i=1;i<=n;i++){
            if(x[i].size()==n-1)y.push_back(i);
        }
        for(int i=0;i<y.size();i++){
            bool f=1;
            for(int j=0;j<=n;j++){
                if(x[j].find(y[i])!=x[j].end())f=0;
            }
            if(f)return y[i];
        }
        return -1;
    }
};