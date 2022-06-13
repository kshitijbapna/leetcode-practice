// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
        int cnt(int n){
            int k=5,cnt=0;
            while(1){
                cnt+=n/k;
                k*=5;
                if(n/k==0)break;
            }
            return cnt;
        }
        int findNum(int n)
        {
            int l=0,r=1e7;
            while(l<=r){
                int mid=(l+r)/2;
                if(cnt(mid)>=n){
                    r=mid-1;
                }
                else{
                    l=mid+1;
                }
            }
            return l;
        }
};

// { Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Solution ob;
        cout <<ob.findNum(n) << endl;
    }
return 0;
}  // } Driver Code Ends