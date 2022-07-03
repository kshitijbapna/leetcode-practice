// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
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
    int wordBreak(string A, vector<string> &B) {
        for(auto word : B)
        words.insert(word);
        string t,curr;
        solve(0,A,t,curr);
        return ans.size()>0;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}
  // } Driver Code Ends