// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    bool isValid(int a[],int N,int M,long long val){
        long long  x=1,curr_pages=0;
        for(int i=0;i<N;i++){
            if(a[i]+curr_pages<=val){
                curr_pages+=a[i];
            }
            else{
                x++;
                curr_pages=a[i];
            }
            if(a[i]>val)return 0;
        }
        return x<=M;
    }
    int findPages(int A[], int N, int M) 
    {
        long long l=0,r=1e12,ans=0;
        while(l<=r){
            long long mid=(l+r)/2;
            if(isValid(A,N,M,mid)){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
            // cout<<l<<" "<<r<<"\n";
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends