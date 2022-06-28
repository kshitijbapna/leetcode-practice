// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int prefixStrings(int n)
	{
	   long long dp[n+1]={0};
       dp[0]=1;
       dp[1]=1;
       for(int i=2;i<=n;i++){
           int l=0,r=i-1;
           while(l<=i-1){
               dp[i]=(dp[i]+(dp[l]*dp[r]))%1000000007;
               l++;
               r--;
           }
       }
       return (int)dp[n]%1000000007;
	}

};
	

// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
       	int n;
       	cin >> n;

       

        Solution ob;
        cout << ob.prefixStrings(n);
	    cout << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends