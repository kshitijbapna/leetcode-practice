// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int minFlips (string s);
int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;

        cout << minFlips (s) << endl;
    }
}
// Contributed By: Pranay Bansal
// } Driver Code Ends


int minFlips (string S)
{
    int k1=0,k2=0;
    for(int i=0;i<S.size();i++){
        if(i%2!=S[i]-'0')k1++;
        if(i%2==S[i]-'0')k2++;
    }
    // cout<<k1<<" "<<k2<<"\n";
    return min(k1,k2);
}