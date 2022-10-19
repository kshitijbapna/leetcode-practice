class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,-1));
        queue<vector<int>> q;
        //(x,y,current path length,number of obstacles we can still remove)
        q.push({0,0,0,k});
        while(!q.empty()){
            auto t=q.front();
            int x=t[0],y=t[1],curr=t[2],rem=t[3];
            q.pop();
            if(x<0||y<0||x>=n||y>=m)continue;
            if(x==n-1&&y==m-1)
                return curr;
            if(grid[x][y]==1){
                if(rem>0)rem--;
                else continue;
            }
            if(vis[x][y]!=-1&&vis[x][y]>=rem)
                continue;
            vis[x][y]=rem;
            q.push({x+1,y,curr+1,rem});
            q.push({x,y+1,curr+1,rem});
            q.push({x-1,y,curr+1,rem});
            q.push({x,y-1,curr+1,rem});
        }
        return -1;
    }
};