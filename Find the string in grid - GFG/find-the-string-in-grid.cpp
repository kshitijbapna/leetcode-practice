// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool valid(vector<vector<char>> g,string word,int i,int j){
        bool f=0;
        int k,x,y,n=g.size(),m=g[0].size();
        k=0;
        x=i,y=j;
        while(y<m&&k<word.size()){
            if(g[x][y]==word[k]){
                k++;
                y++;
            }
            else break;
        }
        if(k==word.size())return 1;
        k=0;
        x=i,y=j;
        while(y>=0&&k<word.size()){
            if(g[x][y]==word[k]){
                k++;
                y--;
            }
            else break;
        }
        if(k==word.size())return 1;
        k=0;
        x=i,y=j;
        while(x<n&&k<word.size()){
            if(g[x][y]==word[k]){
                k++;
                x++;
            }
            else break;
        }
        if(k==word.size())return 1;
        k=0;
        x=i,y=j;
        while(x>=0&&k<word.size()){
            if(g[x][y]==word[k]){
                k++;
                x--;
            }
            else break;
        }
        if(k==word.size())return 1;
        
        k=0;
        x=i,y=j;
        while(x>=0&&y>=0&&k<word.size()){
            if(g[x][y]==word[k]){
                k++;
                x--;
                y--;
            }
            else break;
        }
        if(k==word.size())return 1;
        
        k=0;
        x=i,y=j;
        while(x>=0&&y<m&&k<word.size()){
            if(g[x][y]==word[k]){
                k++;
                x--;
                y++;
            }
            else break;
        }
        if(k==word.size())return 1;
        
        k=0;
        x=i,y=j;
        while(x<n&&y<m&&k<word.size()){
            if(g[x][y]==word[k]){
                k++;
                x++;
                y++;
            }
            else break;
        }
        if(k==word.size())return 1;
        
        k=0;
        x=i,y=j;
        while(x<n&&y>=0&&k<word.size()){
            if(g[x][y]==word[k]){
                k++;
                x++;
                y--;
            }
            else break;
        }
        if(k==word.size())return 1;
        return 0;
        
        
        
    }
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    vector<vector<int>> ans;
	    for(int i=0;i<grid.size();i++){
	        for(int j=0;j<grid[0].size();j++){
	            if(valid(grid,word,i,j))ans.push_back({i,j});
	        }
	    }
	    return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
	}
	return 0;
}  // } Driver Code Ends