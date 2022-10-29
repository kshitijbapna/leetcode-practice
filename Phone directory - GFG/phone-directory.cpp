//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        map<string,set<string>> m;
        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
            string y;
            for(int j=0;j<6;j++){
                y+=contact[i][j];
                m[y].insert(contact[i]);
            }
        }
        string y;
        for(int i=0;i<s.size();i++){
            y+=s[i];
            vector<string> curr;
            for(auto &x : m[y])curr.push_back(x);
            if(curr.size()==0)curr.push_back("0");
            ans.push_back(curr);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends