//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> satisfyEqn(int A[], int n) {
        vector<int> res;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                for(int k=0; k<n; k++){
                    for(int l=0; l<n; l++){
                        if((A[i]+A[j])==(A[k]+A[l])&&(i<j&&k<l)&&(i<k)&&(j!=k)&&(j!=l))
                        {
                            res.push_back(i);
                            res.push_back(j);
                            res.push_back(k);
                            res.push_back(l);
                            return res;}}}}}
        if(res.size()==0){
            res.push_back(-1);
            res.push_back(-1);
            res.push_back(-1);res.push_back(-1);
            return res;
        }
        else return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        vector<int> ptr = ob.satisfyEqn(A,N);
        
        cout<<ptr[0]<<" "<<ptr[1]<<" "<<ptr[2]<<" "<<ptr[3]<<endl;
    }
    return 0;
}
// } Driver Code Ends