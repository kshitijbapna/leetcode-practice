// { Driver Code Starts
#include <iostream>
using namespace std;


 // } Driver Code Ends
class Solution{
public:
    
    long posIntSol(string s)
    {
        int n=1,in=-1;
        for(int i=0;i<s.size();i++)if(s[i]=='+')n++;
        else if(s[i]=='=')in=i;
        string t;
        in++;
        while(in<s.size()){
            t+=s[in++];
        }
        int k=stoi(t);
        if(k<n)return 0;
        // k-1 C n-1
        
        long long ans=1;
        if(n-1<k-n){
            n=k-n+1;
        }
        for(long long i=n;i<=k-1;i++){
            ans*=i;
        }
        for(long long i=1;i<=k-n;i++){
            ans/=i;
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.posIntSol(s)<<endl;
    }
    return 0;
}
  // } Driver Code Ends