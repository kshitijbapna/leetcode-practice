// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int median(vector<vector<int>> &matrix, int r, int c){
        int mi=INT_MAX,ma=INT_MIN;
        for(int i=0;i<r;i++){
            mi=min(mi,matrix[i][0]);
            ma=max(ma,matrix[i][c-1]);
        }
        
        while(mi<ma){
            int mid=(mi+ma)/2;
            int cnt=0;
            for(int i=0;i<r;i++){
                cnt+=upper_bound(matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin();
            }
            if(cnt<(r*c+1)/2){
                mi=mid+1;
            }
            else{
                ma=mid;
            }
        }
        return mi;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
}  // } Driver Code Ends