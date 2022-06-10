// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    string smallestNumber(int S, int D){
        int init_sum=D*9;
        if(S>init_sum)return "-1";
        string ans;
        for(int i=0;i<D;i++)ans+='9';
        for(int i=0;i<D;i++){
            int x;
            if(i==0)x=min(init_sum-S,8);
            else x=min(init_sum-S,9);
            init_sum-=x;
            ans[i]-=x;
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
        int S,D;
        cin >> S >> D;
        Solution ob;
        cout << ob.smallestNumber(S,D) << endl;
    }
    return 0; 
}   // } Driver Code Ends