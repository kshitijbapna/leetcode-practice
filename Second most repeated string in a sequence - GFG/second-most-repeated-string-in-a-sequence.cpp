// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
  public:
    string secFrequent (string arr[], int n)
    {
        map<string,int> m;
        for(int i=0;i<n;i++)m[arr[i]]++;
        int mx=0,smx=0;
        string ans;
        for(auto x : m)mx=max(x.second,mx);
        for(auto x : m){
            if(x.second<mx&&x.second>smx){
                smx=x.second;
                ans=x.first;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        Solution ob;
        cout << ob.secFrequent (arr, n) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends