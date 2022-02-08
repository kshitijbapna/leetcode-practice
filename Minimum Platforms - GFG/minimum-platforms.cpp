// { Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	vector<pair<int,int>> v;
    	for(int i=0;i<n;i++)v.push_back({arr[i],-1});
    	for(int i=0;i<n;i++)v.push_back({dep[i],1});
    	sort(v.begin(),v.end());
    	int plat=0,maxi=0;
    	for(int i=0;i<v.size();i++){
    	    plat+=(-1*v[i].second);
    	    maxi=max(maxi,plat);
    	}
    	return maxi;
    }
};


// { Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}  // } Driver Code Ends