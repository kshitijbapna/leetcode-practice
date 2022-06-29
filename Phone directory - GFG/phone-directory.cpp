// { Driver Code Starts
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
        for(int i=0;i<n;i++){
            string x;
            int j=0;
            while(x.size()<6){
                x+=contact[i][j++];
                m[x].insert(contact[i]);
            }
        }
        vector<vector<string>> ans;
        string k;
        int i=0;
        while(k.size()<s.size()){
            k+=s[i++];
            vector<string> curr(m[k].begin(),m[k].end());
            if(curr.size()>0)
            ans.push_back(curr);
            else{
                curr.push_back("0");
                ans.push_back(curr);
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

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
}  // } Driver Code Ends