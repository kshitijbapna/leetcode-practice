// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
vector<int> find(int a[], int n , int x )
{
    int k1=-1,k2=-1;
    int l1=0,r1=n-1,l2=0,r2=n-1;
    while(l1<=r1){
        int mid=(l1+r1)/2;
        if(a[mid]==x){
            k1=mid;
            r1=mid-1;
        }
        else if(a[mid]>x){
            r1=mid-1;
        }
        else{
            l1=mid+1;
        }
    }
    while(l2<=r2){
        int mid=(l2+r2)/2;
        if(a[mid]==x){
            k2=mid;
            l2=mid+1;
        }
        else if(a[mid]>x){
            r2=mid-1;
        }
        else{
            l2=mid+1;
        }
    }
    return {k1,k2};
}

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}


  // } Driver Code Ends