// { Driver Code Starts
// C++ program to check if two strings are isomorphic


#include<bits/stdc++.h>


using namespace std;
#define MAX_CHARS 256

 // } Driver Code Ends
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        if(str1.size()!=str2.size())return 0;
        set<char> s;
        bool cng[str1.size()]={0};
        for(int i=0;i<str1.size();i++){
            if(str1[i]!=str2[i]){
                if(s.find(str1[i])==s.end()){
                    s.insert(str1[i]);
                    char ch=str2[i];
                    for(int j=0;j<str2.size();j++)if(str2[j]==ch&&cng[j]==0){
                        str2[j]=str1[i];
                        cng[j]=1;
                    }
                }
                else return 0;
            }
        }
        return str1==str2;
    }
};

// { Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}  // } Driver Code Ends