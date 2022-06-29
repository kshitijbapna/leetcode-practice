// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    
    public:
    int transfigure (string A, string B)
    {
    	map<char,int> m;
    	for(int i=0;i<A.size();i++)m[A[i]]++;
    	for(int i=0;i<B.size();i++)m[B[i]]--;
    	for(auto x : m)if(x.second!=0)return -1;
    	int n=A.size(),i=n-1,j=n-1,ans=0;
    	while(i>=0){
    	    if(A[i]==B[j]){
    	        j--;
    	    }
    	    else{
    	        ans++;
    	    }
    	    i--;
    	}
    	return ans;
    }
};

// { Driver Code Starts.


int main () 
{
    int t; cin >> t;
    while (t--)
    {
        string A, B; 
        cin >> A >> B;
        Solution obj;
        cout << obj.transfigure (A, B) << endl;
    }
}  // } Driver Code Ends