// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
		vector<string> AllPossibleStrings(string s){
		    vector<string> ans;
		    for(int i=1;i<pow(2,s.size());i++){
		        int tm=i,j=0;
		        string y;
		        while(tm>0){
		            if(tm%2==1)y+=s[j];
		            j++;
		            tm/=2;
		        }
		        ans.push_back(y);
		    }
		    sort(ans.begin(),ans.end());
		    return ans;
		}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}  // } Driver Code Ends