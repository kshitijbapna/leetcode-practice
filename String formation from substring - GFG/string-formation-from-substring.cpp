// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
		
	int isRepeat(string s)
	{
	    int n=s.size();
	    if(n==1)return 0;
	    for(int i=1;i*i<=n;i++){
	        if(n%i==0){
	            int a=n/i,b=i;
	            bool f=1;
	            //aaa aaa aaa aaa
	            if(b>1){
	            for(int j=0;j<b;j++){
	                for(int k=0;k<a;k++){
	                   // cout<<j*a+k<<" "<<k<<"\n";
	                    if(s[j*a+k]!=s[k]){
	                        f=0;
	                        break;
	                    }
	                }
	            }
	            if(f)return 1;}
	            f=1;
	            for(int k=0;k<a;k++){
	                for(int j=0;j<b;j++){
	                    if(s[k*b+j]!=s[j]){
	                       // cout<<k*b+j<<" "<<j<<"\n";
	                        f=0;
	                        break;
	                    }
	                }
	            }
	            if(f)return 1;
	        }
	    }
	    return 0;
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
   		string str;
   		cin >> str;
        Solution ob;
   		cout << ob.isRepeat(str) << "\n";
   	}

    return 0;
}  // } Driver Code Ends