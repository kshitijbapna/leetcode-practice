// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minimumDays(int S, int N, int M){
        int ans=(S*M+N-1)/N,day=1,food=0;
        while(day<=S){
            if(day%7==0){
                food-=M;
                if(food<0)return -1;
            }else{
                food+=N;
                food-=M;
                if(food<0)return -1;
            }
            day++;
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int S, N, M;
        cin>> S >> N >> M;
        
        Solution ob;
        cout<<ob.minimumDays(S, N, M)<<endl;
    }
    return 0;
}  // } Driver Code Ends