class Solution {
public:
    int dir[4][2]={{1,0},{-1,0},{0,-1},{0,1}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> v(n,vector<int>(m,INT_MAX));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    v[i][j]=0;
                }
            }
        }
        while(q.size()>0){
            auto [sx,sy]=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int x=sx+dir[i][0],y=sy+dir[i][1];
                if(x>=0&&y>=0&&x<n&&y<m&&v[x][y]==INT_MAX){
                    q.push({x,y});
                    v[x][y]=v[sx][sy]+1;
                }
            }
        }
        return v;
    }
};