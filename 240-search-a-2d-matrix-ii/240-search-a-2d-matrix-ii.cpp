class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(),m=matrix[0].size(),i=0,j=matrix[0].size()-1;
        while(i<n&&j>=0){
            if(matrix[i][j]==target)return 1;
            else if(matrix[i][j]>target)j--;
            else if(matrix[i][j]<target)i++;
        }
        return 0;
    }
};