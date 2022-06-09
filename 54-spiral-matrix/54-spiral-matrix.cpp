class Solution {
public:
    vector<int> ans;
    void move(vector<vector<int>>& a,char d,int i,int j){
        int n=a.size(),m=a[0].size();
        if(a[i][j]==-1000)return;
        ans.push_back(a[i][j]);
        a[i][j]=-1000;
        if(d=='R'){
            if(j+1==m||a[i][j+1]==-1000){
                move(a,'D',i+1,j);
            }
            else{
                move(a,'R',i,j+1);
            }
        }
        else if(d=='U'){
            if(a[i-1][j]==-1000){
                move(a,'R',i,j+1);
            }
            else{
                move(a,'U',i-1,j);
            }
        }
        else if(d=='D'){
            if(i+1==n||a[i+1][j]==-1000){
                move(a,'L',i,j-1);
            }
            else{
                move(a,'D',i+1,j);
            }
        }
        else if(d=='L'){
            if(j==0||a[i][j-1]==-1000){
                move(a,'U',i-1,j);
            }
            else{
                move(a,'L',i,j-1);
            }
        }
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        if(n==1)return matrix[0];
        if(m==1){
            for(int i=0;i<n;i++){
                ans.push_back(matrix[i][0]);
            }
            return ans;
        }
        if(n==1&&m==1)return {matrix[0][0]};
        move(matrix,'R',0,0);
        return ans;
    }
};