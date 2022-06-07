// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    int dir[8][2]={{2,1},{-2,-1},{-2,1},{2,-1},{1,2},{-1,-2},{1,-2},{-1,2}};
	
	int minStepToReachTarget(vector<int>&K,vector<int>&T,int N)
	{
	    vector<vector<int>> vis(N,vector<int>(N,INT_MAX));
	    vis[K[0]-1][K[1]-1]=0;
	    queue<pair<int,int>> q;
	    q.push({K[0]-1,K[1]-1});
	    while(!q.empty()){
	        pair<int,int> x=q.front();
	        q.pop();
	        for(int i=0;i<8;i++){
	            int xx=x.first+dir[i][0],yy=x.second+dir[i][1];
	            if(xx>=0&&yy>=0&&xx<N&&yy<N&&vis[xx][yy]==INT_MAX){
	                q.push({xx,yy});
	                vis[xx][yy]=vis[x.first][x.second]+1;
	            }
	        }
	    }
	    return vis[T[0]-1][T[1]-1];
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends