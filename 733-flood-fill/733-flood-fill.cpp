class Solution {
public:
    bool vis[55][55]; 
    int dir[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
    void dfs(vector<vector<int>>& im,int x,int y,int ne,int pc){
        int n=im.size(),m=im[0].size();
        // if(!(x<n&&x>=0&&y<m&&y>=0))return;
        vis[x][y]=1;
        im[x][y]=ne;
        for(int i=0;i<4;i++){
            int xx=x+dir[i][0],yy=y+dir[i][1];
            if(xx<n&&xx>=0&&yy<m&&yy>=0&&vis[xx][yy]==0&&im[xx][yy]==pc){
                dfs(im,xx,yy,ne,pc);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        dfs(image,sr,sc,newColor,image[sr][sc]);
        return image;
    }
};