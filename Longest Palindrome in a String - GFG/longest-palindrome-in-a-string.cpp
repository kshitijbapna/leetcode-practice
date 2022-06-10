// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    string longestPalin (string S) {
        int n=S.size(),ans=0;
        string an;
        for(int i=0;i<n;i++){
            int l=i-1,r=i+1,k=1;
            while(l>=0&&r<n&&S[l]==S[r]){
                l--;
                r++;
                k+=2;
            }
            if(k>ans){
                l++;
                r--;
                an="";
                for(int kk=l;kk<=r;kk++)an+=S[kk];
                ans=k;
            }
            l=i,r=i+1;
            k=0;
            while(l>=0&&r<n&&S[l]==S[r]){
                l--;
                r++;
                k+=2;
            }
            if(k>ans){
                l++;
                r--;
                an="";
                for(int kk=l;kk<=r;kk++)an+=S[kk];
                ans=k;
            }
        }
        
        return an;
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends