// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    set<string> words;
    vector<string> ans;
    void solve(int i,string &s,string t,string curr){
        if(i>=s.size())return;
        t+=s[i];
        solve(i+1,s,t,curr);
        if(words.find(t)!=words.end()){
            curr+=t;
            if(i!=s.size()-1)curr+=" ";
            else ans.push_back(curr);
            t="";
            solve(i+1,s,t,curr);
        }
        
    }
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        for(auto word : dict)
        words.insert(word);
        string t,curr;
        solve(0,s,t,curr);
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends