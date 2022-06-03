class NumMatrix {
public:
    vector<vector<int>> v;
    NumMatrix(vector<vector<int>>& matrix) {
        v=matrix;
        int n=v.size(),m=v[0].size();
        for(int j=0;j<m;j++)
        for(int i=1;i<n;i++)v[i][j]+=v[i-1][j];  
        for(int i=0;i<n;i++)
        for(int j=1;j<m;j++)v[i][j]+=v[i][j-1];
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum=v[row2][col2];
        row1--;
        col1--;
        if(row1>=0&&col1>=0){
            sum=v[row2][col2]+v[row1][col1]-v[row2][col1]-v[row1][col2];
        }
        else if(row1>=0){
            sum=v[row2][col2]-v[row1][col2];
        }
        else if(col1>=0){
            sum=v[row2][col2]-v[row2][col1];
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */