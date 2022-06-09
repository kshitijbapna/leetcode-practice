// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


 // } Driver Code Ends

class Solution 
{
    public:
    //Function to find a solved Sudoku.
    bool ff=0;
    int ans[9][9];
    void solve(int r,int c,vector<vector<int>>& a){
        if(ff)return;
        if(r>=9){
            for(int i=0;i<9;i++)for(int j=0;j<9;j++)ans[i][j]=a[i][j];
            ff=1;
            return;
        }
        if(c>=9){
            solve(r+1,0,a);
            return;
        }
        if(a[r][c]!=0){
            // if(c<9)
            solve(r,c+1,a);
            return;
        }
        for(int i=1;i<=9;i++){
            bool f=1;
            for(int j=0;j<9;j++){
                if(a[r][j]==i)f=0;
                if(a[j][c]==i)f=0;
            }
            int sr=r/3,sc=c/3;
            for(int j=sr*3;j<sr*3+3;j++){
                for(int k=sc*3;k<sc*3+3;k++){
                    if(a[j][k]==i)f=0;
                }
            }
            if(f){
                a[r][c]=i;
                solve(r,c+1,a);
                a[r][c]=0;
            }
        }
    }
    bool SolveSudoku(int grid[N][N])  
    {
        vector<vector<int>> v(9,vector<int>(9));
        for(int i=0;i<9;i++)for(int j=0;j<9;j++)v[i][j]=grid[i][j];
        solve(0,0,v);
        return ff;
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cout<<ans[i][j]<<" ";
            }
        } 
    }
};

// { Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}  // } Driver Code Ends