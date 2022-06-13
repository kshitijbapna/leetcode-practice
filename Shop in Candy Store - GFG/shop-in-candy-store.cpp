// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        int min_cost=0,max_cost=0;
        int l=0,r=N-1;
        sort(candies,candies+N);
        while(l<=r&&l<N){
            min_cost+=candies[l];
            int k=K;
            while(r>l&&k--){
                r--;
            }
            l++;
        }
        l=0,r=N-1;
        while(l<=r&&l<N){
            max_cost+=candies[r];
            int k=K;
            while(r>l&&k--){
                l++;
            }
            r--;
        }
        return {min_cost,max_cost};
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}  // } Driver Code Ends