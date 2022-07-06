// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int kadane(vector<int> &arr){
        int mx=0,gmx=INT_MIN;
        for(int i=0;i<arr.size();i++){
            mx+=arr[i];
            gmx=max(gmx,mx);
            if(mx<0)mx=0;
        }
        return gmx;
    }
    int maximumSumRectangle(int R, int C, vector<vector<int>> M) {
        vector<vector<int>> y=M;
        for(int i=1;i<R;i++){
            for(int j=0;j<C;j++){
                y[i][j]+=y[i-1][j];
            }
        }
        int ans=INT_MIN;
        for(int r1=0;r1<R;r1++){
            for(int r2=r1;r2<R;r2++){
                vector<int> arr;
                if(r1==0){
                    for(int i=0;i<C;i++)arr.push_back(y[r2][i]);
                }
                else{
                    for(int i=0;i<C;i++)arr.push_back(y[r2][i]-y[r1-1][i]);
                }
                ans=max(ans,kadane(arr));
            }
        }
        return ans;
    }
};


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        Solution ob;
        cout << ob.maximumSumRectangle(N, M, v) << "\n";
    }
}  // } Driver Code Ends