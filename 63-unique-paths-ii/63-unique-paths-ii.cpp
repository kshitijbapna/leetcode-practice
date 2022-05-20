class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& o) {
        int m=o.size(),n=o[0].size();
        if(o[m-1][n-1]==1||o[0][0]==1)return 0;
        vector<vector<int>> v(m,vector<int>(n));
        v[0][0]=1;
        for(int i=1;i<n;i++)if(o[0][i]==0)v[0][i]=v[0][i-1];
        for(int i=1;i<m;i++)if(o[i][0]==0)v[i][0]=v[i-1][0];
        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(o[i][j]==0){
                    v[i][j]=v[i-1][j]+v[i][j-1];
                }
            }
        }
        return v[m-1][n-1];
    }
};