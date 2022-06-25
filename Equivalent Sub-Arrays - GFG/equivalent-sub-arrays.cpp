// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
public:
    int countDistinctSubarray(int arr[], int n)
    {
        int ans=0;
        map<int,int> m;
        set<int> s;
        for(int i=0;i<n;i++)s.insert(arr[i]);
        int i=0,j=0,k=s.size();
        for(int i=0;i<n;i++){
            m[arr[i]]++;
            while(m.size()==k&&j<=i){
                ans+=n-i;
                m[arr[j]]--;
                if(m[arr[j]]==0)m.erase(arr[j]);
                j++;
            }
        }
        return ans;
    }
};


// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;	
		cout<<ob.countDistinctSubarray(a,n)<<endl;
	}
	return 0;
}  // } Driver Code Ends