class Solution {
public:
    bool check(vector<vector<bool>>& board,int r,int c){
        int n=board.size();
        for(int i=0;i<=r;i++){
            if(board[i][c])return 0;
            if(r-i>=0&&c-i>=0&&board[r-i][c-i])return 0;
            if(r-i>=0&&c+i<n&&board[r-i][c+i])return 0;
        }
        return 1;
    }
    int solve(vector<vector<bool>>& board, int row){
        if(row==board.size())return 1;
        int cnt=0;
        for(int col=0;col<board.size();col++){
            if(check(board,row,col)){
                board[row][col]=1;
                cnt+=solve(board,row+1);
                board[row][col]=0;
            }
        }
        return cnt;
    }
    int totalNQueens(int n) {
        vector<vector<bool>> board(n,vector<bool>(n,0));
        return solve(board,0);
    }
};