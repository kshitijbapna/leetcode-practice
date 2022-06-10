// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
        bool found[100001];
        memset(found,0,sizeof(found));
        for(int i=0;i<N;i++)found[arr[i]]=1;
        int ans=0,k=0;
        for(int i=0;i<100001;i++){
            if(found[i]){
                k++;
                ans=max(ans,k);
            }
            else{
                k=0;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}  // } Driver Code Ends