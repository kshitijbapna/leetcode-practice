class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int cur=1;
        vector<vector<int>> v(n,vector<int>(n,-1));
        char dir='L';
        int i=0,j=0;
        while(cur<=n*n){
            v[i][j]=cur++;
            if(dir=='L'){
                if(j==n-1||v[i][j+1]!=-1){
                    dir='D';
                    i++;
                }
                else j++;
            }
            else if(dir=='R'){
                if(j==0||v[i][j-1]!=-1){
                    dir='U';
                    i--;
                }
                else j--;
            }
            else if(dir=='U'){
                if(i==0||v[i-1][j]!=-1){
                    dir='L';
                    j++;
                }
                else i--;
            }
            else if(dir=='D'){
                if(i==n-1||v[i+1][j]!=-1){
                    dir='R';
                    j--;
                }
                else i++;
            }
        }
        return v;
    }
};