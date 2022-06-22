// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    long long int maximizeSum(long long int a[], int n, int k)
    {
        long long int ans=0;
        sort(a,a+n);
        int i=0;
        while(i<n){
            if(a[i]>=0)break;
            if(k>0){
                a[i]=-a[i];
                k--;
            }
            if(k==0)break;
            i++;
        }
        sort(a,a+n);
        if(k%2){
            a[0]=-a[0];
        }
        // cout<<k<<"\n";
        for(int i=0;i<n;i++){
            // cout<<a[i]<<" ";
            ans+=a[i];
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
         int n, k;
         cin>>n>>k;
         long long int a[n+5];
         for(int i=0;i<n;i++)
         cin>>a[i];
         Solution ob;
         cout<<ob.maximizeSum(a, n, k)<<endl;
     }
	
	return 0;
}  // } Driver Code Ends