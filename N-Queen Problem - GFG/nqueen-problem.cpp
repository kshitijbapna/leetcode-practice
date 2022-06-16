// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<int>> ans;
    void solve(int i,int j,int n,vector<vector<int>> &b,int done,vector<int> xx){
        if(i>done)return;
        if(j>=n){
            solve(i+1,0,n,b,done,xx);
            return;
        }
        if(i>=n){
            if(done==n){
                ans.push_back(xx);
            }
            return;
        }
        bool f=1;
        for(int ii=0;ii<n;ii++){
            if(b[i][ii]==1)f=0;
            if(b[ii][j]==1)f=0;
        }
        int x,y;
        x=i,y=j;
        while(x<n&&y<n){
            if(b[x][y]==1)f=0;
            x++;
            y++;
        }
        x=i,y=j;
        while(x<n&&y>=0){
            if(b[x][y]==1)f=0;
            x++;
            y--;
        }
        x=i,y=j;
        while(x>=0&&y>=0){
            if(b[x][y]==1)f=0;
            x--;
            y--;
        }
        x=i,y=j;
        while(x>=0&&y<n){
            if(b[x][y]==1)f=0;
            x--;
            y++;
        }
        if(f==1){
            b[i][j]=1;
            xx.push_back(j+1);
            solve(i,j+1,n,b,done+1,xx);
            xx.pop_back();
            b[i][j]=0;
            solve(i,j+1,n,b,done,xx);
        }
        else{
            solve(i,j+1,n,b,done,xx);
        }
    }
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> b(n,vector<int>(n,0));
        vector<int> xx;
        solve(0,0,n,b,0,xx);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends