// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int findSubString(string str)
    {
        int n=str.size();
        unordered_map<char,int> m;
        for(int i=0;i<n;i++)m[str[i]]=0;
        int i=0,j=0,ans=INT_MAX,cnt=0;
        string res;
        while(j<n){
            if(m[str[j]]==0)cnt++;
            m[str[j]]+=1;
            if(cnt==m.size()){
                while(i<n&&m[str[i]]>1){
                    m[str[i]]--;
                    i++;
                }
                if(ans>(j-i+1)){
                    ans=j-i+1;
                }
            }
            j++;
        }
        return ans;
    }
};

// { Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}  // } Driver Code Ends