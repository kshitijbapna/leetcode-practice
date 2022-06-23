// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        multiset<int> m;
        for(int i=0;i<k;i++)m.insert(-arr[i]);
        vector<int> ans;
        ans.push_back(-1*(*m.begin()));
        for(int i=1;i<=n-k;i++){
            m.erase(m.find(-arr[i-1]));
            m.insert(-arr[i+k-1]);
            ans.push_back(-1*(*m.begin()));
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}  // } Driver Code Ends