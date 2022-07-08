// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int romanToDecimal(string &str) {
        unordered_map<char,int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
        
        int res;
        res = mp[str[0]];
        if(str.length()==1)
        {
            return res;
        }
    
         
        for(int i=1;i<str.length();i++)
        {
            if(mp[str[i-1]]>=mp[str[i]])
            {
                res+=mp[str[i]];
            }
            else
            {
                res+= (mp[str[i]]- 2*mp[str[i-1]]);
            }
        }
        return res;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}  // } Driver Code Ends