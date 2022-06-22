// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool checkP(string str,int i){
        int l=0,r=i;
        while(l<r){
            if(str[l]!=str[r])return 0;
            l++;
            r--;
        }
        return 1;
    }
    int minChar(string str){
        int n=str.size(),i=0,len=0;
        while(i<n){
            if(checkP(str,i)){
                len=max(len,i+1);
            }
            i++;
        }
        return n-len;
    }
};


// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin >> str;
	    Solution ob;
	    int ans = ob.minChar(str);
	    cout << ans<<endl;
	}
	return 0;
}
  // } Driver Code Ends