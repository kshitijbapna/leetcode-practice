// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	    int nextPermutation(string &S){
	        int n=S.size(),k,l;
	        for(k=n-2;k>=0;k--){
	            if(S[k]<S[k+1])break;
	        }
	        if(k<0)return -1;
	        for(l=n-1;l>k;l--){
	            if(S[l]>S[k])break;
	        }
	        swap(S[l],S[k]);
	        reverse(S.begin()+k+1,S.end());
	        return 1;
	    }
	    
		vector<string>find_permutation(string S)
		{
		    sort(S.begin(),S.end());
		    vector<string> ans;
		    ans.push_back(S);
		    while(nextPermutation(S)!=-1){
		        ans.push_back(S);
		    }
		    return ans;
		}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends