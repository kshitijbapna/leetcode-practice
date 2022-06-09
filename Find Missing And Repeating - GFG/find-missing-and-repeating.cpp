// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        int i=0,rep=-1;
        long long sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        while(i<n){
            if(arr[i]==i+1)i++;
            else{
                int tmp=arr[arr[i]-1];
                if(tmp==arr[i]){
                    rep=arr[i];
                    break;
                }
                arr[arr[i]-1]=arr[i];
                arr[i]=tmp;
            }
        }
        int* ans=new int[2];
        ans[0]=rep;
        ans[1]=rep-sum+(long long)n*(n+1)/2ll;
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends