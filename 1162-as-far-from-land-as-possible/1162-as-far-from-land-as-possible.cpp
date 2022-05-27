class Solution {
public:
    int dir[4][2]={{1,0},{-1,0},{0,-1},{0,1}};
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int,int>> q;
        
        // step 1 : pushing all coordinates of land
        for(int i=0 ; i<n ; i++)
            for(int j=0 ; j<m ; j++)
                if(grid[i][j] == 1)
                    q.push({i,j});
    
        // if matrix has no water then ans = -1 so return 
        if(q.size() == n*m)
            return -1;
        
        int dist = 0;
        
        // standard BFS
        while(q.size())
        {
            int size = q.size();
            dist++;
            while(size--)
            {
                auto [si , sj] = q.front(); q.pop();
                
                for(int i=0 ; i<4; i++)
                {
                    int newi = si + dir[i][0];
                    int newj = sj + dir[i][1];
                    if(newi>=0 and newi<n and newj>=0 and newj<m and grid[newi][newj] == 0)
                        q.push({newi,newj}) , grid[newi][newj] = 1;
                }
            }  
        }
        return dist-1;
    }
};