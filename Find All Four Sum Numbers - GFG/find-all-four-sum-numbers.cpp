// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int>> fourSum(vector<int> &a, int target) {
        set<vector<int>> s;
        sort(a.begin(),a.end());
        int n=a.size();
        vector<vector<int>> ans;
        // s.insert(make_tuple(1,2,3,4));
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    int x=target-a[i]-a[j]-a[k];
                    int in=lower_bound(a.begin()+k+1,a.end(),x)-a.begin();
                    if(in!=n&&a[in]==x){
                        vector<int> y{a[i],a[j],a[k],a[in]};
                        if(s.find(y)==s.end()){
                            ans.push_back(y);
                            s.insert(y);
                        }
                    }
                }
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends