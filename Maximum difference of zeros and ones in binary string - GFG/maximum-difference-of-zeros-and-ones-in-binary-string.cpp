// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int maxSubstring(string S)
	{
	    int global_max=-1,curr_max=0;
	    for(int i=0;i<S.size();i++){
	        if(S[i]=='0')curr_max++;
	        else curr_max--;
	        global_max=max(global_max,curr_max);
	        if(curr_max<0)curr_max=0;
	    }
	    return global_max;
	}
};

// { Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.maxSubstring(s) << "\n";
   	}

    return 0;
}
  // } Driver Code Ends