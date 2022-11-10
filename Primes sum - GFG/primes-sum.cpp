//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
public:
    bool isP(int N){
        for(int i=2;i<=sqrt(N);i++){
            if(N%i==0)return 0;
        }
        return 1;
    }
    string isSumOfTwo(int N){
        for(int i=2;i<=N/2;i++){
            int k1=i,k2=N-i;
            if(isP(k1)&&isP(k2))return "Yes";
        }
        return "No";
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.isSumOfTwo(N) << endl;
    }
    return 0;
}

// } Driver Code Ends