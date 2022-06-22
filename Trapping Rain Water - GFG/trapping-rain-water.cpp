// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        int lm[n],rm[n];
        memset(lm,-1,sizeof(lm));memset(rm,-1,sizeof(rm));
        for(int i=0;i<n;i++){
            if(i==0)lm[i]=arr[i];
            else lm[i]=max(lm[i-1],arr[i]);
        }
        for(int j=n-1;j>=0;j--){
            if(j==n-1)rm[j]=arr[j];
            else rm[j]=max(arr[j],rm[j+1]);
        }
        long long ans=0;
        for(int i=1;i<n-1;i++){
            
            long long x=(long long)min(lm[i-1],rm[i+1])-arr[i];
            if(x>0)ans+=x;
            
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}  // } Driver Code Ends