// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the largest number after k swaps.
    void findMax(string str,int k,int i,string &ans){
        if(i==str.size()-1||k==0){
            if(ans<str){
                ans=str;
            }
            return;
        }
        for(int j=i+1;j<str.size();j++){
            if(str[j]>str[i]){
                swap(str[i],str[j]);
                findMax(str,k-1,i+1,ans);
                swap(str[i],str[j]);
            }
        }
        findMax(str,k,i+1,ans);
    }
    string findMaximumNum(string str, int k)
    {
       string ans=str;
       findMax(str,k,0,ans);
       return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends