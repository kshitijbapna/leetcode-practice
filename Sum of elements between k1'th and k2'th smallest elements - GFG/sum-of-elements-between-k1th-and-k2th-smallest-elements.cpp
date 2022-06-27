// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    long long sumBetweenTwoKth( long long A[], long long N, long long K1, long long K2)
    {
        if(K2-K1<=1)return 0;
        sort(A,A+N);
        for(int i=1;i<N;i++)A[i]+=A[i-1];
        // for(int i=0;i<N;i++)cout<<A[i]<<" ";
        if(K1>1)return A[K2-2]-A[K1-1];
        return A[K2-2]-A[0];
    }
};

// { Driver Code Starts.
int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        cin>>n;
        long long a[n+5];
        for(int i =0;i<n;i++)
            cin >> a[i];
        
        long long k1, k2;
        cin >> k1 >> k2;
        Solution ob;
        cout << ob.sumBetweenTwoKth(a, n, k1, k2) << endl;
        
    }
	return 0;
}
  // } Driver Code Ends