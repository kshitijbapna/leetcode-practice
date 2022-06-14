// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        stack<char> s;
        int i=0;
        while(i<x.size()){
            if(x[i]=='('||x[i]=='['||x[i]=='{')s.push(x[i]);
            else{
                if(s.empty())return 0;
                if(s.top()=='('&&x[i]==')')s.pop();
                else if(s.top()=='{'&&x[i]=='}')s.pop();
                else if(s.top()=='['&&x[i]==']')s.pop();
                else return 0;
            }
            i++;
        }
        return s.empty();
    }

};

// { Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}  // } Driver Code Ends