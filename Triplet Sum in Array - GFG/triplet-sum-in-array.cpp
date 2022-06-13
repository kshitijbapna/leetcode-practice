// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
        sort(A,A+n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int zz=X-A[i]-A[j];
                int in=lower_bound(A,A+n,zz)-A;
                // in--;
                // cout<<zz<<" "<<A[i]<<" "<<A[j]<<" "<<A[in]<<"\n";
                // if(in<n)cout<<A[in]<<"\n";
                // else cout<<"\n";
                if(in<n&&in!=i&&in!=j&&A[in]+A[i]+A[j]==X)return 1;
            }
        }
        return 0;
    }

};

// { Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}
  // } Driver Code Ends