// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    vector<pair<int,int>> v(26);
		    string ans;
		    for(int i=0;i<A.size();i++){
		        v[A[i]-'a'].first++;
		        v[A[i]-'a'].second=i;
		        char x='#';
		        int ci=INT_MAX;
		        for(int j=0;j<26;j++){
		            if(v[j].second<ci&&v[j].first==1){
		                x='a'+j;
		                ci=v[j].second;
		            }
		        }
		        ans+=x;
		    }
		    return ans;
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends