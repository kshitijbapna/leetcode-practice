// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends

class Solution{
    public:
    void rem(char prev,string &S,int i){
        if(i>=S.size())return;
        if(S[i]==prev){
            S.erase(S.begin()+i);
            rem(prev,S,i);
        }
        rem(S[i],S,i+1);
    }
    string removeConsecutiveCharacter(string S)
    {
        rem('$',S,0);
        return S;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.removeConsecutiveCharacter(s)<<endl;
    }
} 



  // } Driver Code Ends