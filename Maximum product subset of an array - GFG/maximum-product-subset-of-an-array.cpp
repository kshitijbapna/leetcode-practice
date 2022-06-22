// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    long long int findMaxProduct(vector<int>&a, int n){
        
         long long int mxN=-1,mxP=1,gmax=1,m=1e9+7,ans=0;
         int nc=0,zc=0;
         for(int i=0;i<n;i++){
             if(a[i]!=0)gmax*=a[i];
             if(a[i]<0)nc++;
             if(a[i]==0)zc++;
             gmax%=m;
         }
         if(n==1)return a[0];
         if(nc==1&&zc==n-1)return 0;
         ans=gmax;
         for(int i=0;i<n;i++){
             if(a[i]<0){
                 ans=max(ans,gmax/a[i]);
             }
         }
         return ans;
    }
};



// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<int>arr(n);
	    for(int i = 0 ; i < n; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    long long int ans = ob.findMaxProduct(arr, n);
	    cout << ans<<endl;
	}
	return 0;
}
  // } Driver Code Ends