class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows=matrix.size(),cols=matrix[0].size(),i,j;
        bool r=0,c=0;
        for(int i=0;i<cols;i++)if(matrix[0][i]==0)r=1;
        for(int i=0;i<rows;i++)if(matrix[i][0]==0)c=1;

        // if(matrix[0][0]==0)f=1;
        for(int i=1;i<rows;i++){
            for(int j=1;j<cols;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        for(int i=1;i<rows;i++){
            if(matrix[i][0]==0)
            for(j=0;j<cols;j++)matrix[i][j]=0;
        }
        for(int i=1;i<cols;i++){
            if(matrix[0][i]==0)
            for(int j=0;j<rows;j++)matrix[j][i]=0;
        }
        if(r)for(int i=0;i<cols;i++)matrix[0][i]=0;
        if(c)for(int i=0;i<rows;i++)matrix[i][0]=0;
    }
};