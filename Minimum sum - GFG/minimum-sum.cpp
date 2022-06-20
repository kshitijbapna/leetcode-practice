// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    string solve(int arr[], int n) {
        string a,b;
        sort(arr,arr+n);
        for(int i=0;i<n;i++){
            if(i%2)b+=to_string(arr[i]);
            else a+=to_string(arr[i]);
        }
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        int carry=0;
        string ans;
        for(int i=0;i<b.size();i++){
            int x=a[i]+b[i]-2*'0';
            x+=carry;
            carry=0;
            if(x>9)carry=1;
            x%=10;
            ans+=to_string(x);
        }
        if(carry>0){
            if(a.size()>b.size()){
                if(a[a.size()-1]=='9'){
                    ans+="01";
                }
                else{
                    a[a.size()-1]++;
                    ans+=a[a.size()-1];
                }
            }
            else ans+="1";
        }
        if(carry==0){
            if(a.size()>b.size())ans+=a[a.size()-1];
        }
        reverse(ans.begin(),ans.end());
        while(ans[0]=='0'){
            ans.erase(ans.begin());
        }
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
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.solve(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends