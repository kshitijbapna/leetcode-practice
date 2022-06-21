// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int findSwapValues(int A[], int n, int B[], int m)
	{
	    long long suma=0,sumb=0;
        sort(A,A+n);sort(B,B+m);
        for(int i=0;i<n;i++)suma+=A[i];
        for(int j=0;j<m;j++)sumb+=B[j];
        if((suma+sumb)%2)return -1;
        long long req=(suma+sumb)/2;
        for(int i=0;i<n;i++){
            // req=suma+x-A[i]
            int in=lower_bound(B,B+m,req-suma+A[i])-B;
            if(in==m)in--;
            if(req==suma+B[in]-A[i])return 1;
        }
        return -1;
	}
 

};

// { Driver Code Starts.

int main() 
{
   	
   	int t;
    cin >> t;
    while (t--)
    {
    	int n,m;
        cin>>n>>m;
        int a[n];
        int b[m];
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<m;i++)
            cin>>b[i];
        

        Solution ob;
        cout <<  ob.findSwapValues(a, n, b, m);
	    cout << "\n";
	     
    }
    return 0;
}





  // } Driver Code Ends