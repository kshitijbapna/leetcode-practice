// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  int smallestSumSubarray(vector<int>& a){
      int n=a.size(),gmin=INT_MAX,curr_min=0,f=0;
      for(int i=0;i<n;i++){
          gmin=min(gmin,a[i]);
          if(a[i]<0)f=1;
          curr_min+=a[i];
          if(curr_min>=0)curr_min=0;
          gmin=min(gmin,curr_min);
      }
      if(f==0)return *min_element(a.begin(),a.end());
      return gmin;
  }
};


// { Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        
        Solution ob;
        
        int ans = ob.smallestSumSubarray(a);
        
        cout<<ans<<endl;
    }
}  // } Driver Code Ends