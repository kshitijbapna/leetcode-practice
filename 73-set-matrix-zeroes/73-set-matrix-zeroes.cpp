class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool x[matrix.size()][matrix[0].size()];
        memset(x,0,sizeof(x));
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j]==0&&x[i][j]==0){
                    for(int k=0;k<matrix.size();k++){
                        if(matrix[k][j]!=0)x[k][j]=1;
                        matrix[k][j]=0;
                    }
                    for(int k=0;k<matrix[i].size();k++){
                        if(matrix[i][k]!=0)x[i][k]=1;
                        matrix[i][k]=0;
                    }
                }
            }
        }
        // return matrix;
    }
};