class Solution {
public:
    vector<vector<char>> ans;
    bool f=0;
    void solve(int r,int c,vector<vector<char>> a,int k){
        // cout<<r<<" "<<c<<"\n";
        if(f)return;
        k++;
        if(r>=9){
            ans=a;
            f=1;
            return;
        }
        if(c>=9){
            solve(r+1,0,a,k);
            return;
        }
        if(a[r][c]!='.'){
            // if(c<9)
            solve(r,c+1,a,k);
            return;
        }
        for(int i=1;i<=9;i++){
            bool f=1;
            for(int j=0;j<9;j++){
                if(a[r][j]=='0'+i)f=0;
                if(a[j][c]=='0'+i)f=0;
            }
            int sr=r/3,sc=c/3;
            for(int j=sr*3;j<sr*3+3;j++){
                for(int k=sc*3;k<sc*3+3;k++){
                    if(a[j][k]=='0'+i)f=0;
                }
            }
            if(f){
                // cout<<i<<"\n";
                a[r][c]='0'+i;
                solve(r,c+1,a,k);
                // a[r][c]='.';
            }
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(0,0,board,0);
        board=ans;
    }
};