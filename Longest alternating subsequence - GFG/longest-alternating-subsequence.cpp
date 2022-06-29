// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		int AlternatingaMaxLength(vector<int>&nums){
		    int f=0,n=nums.size(),ans1=0,ans2=0;
		    for(int i=1;i<n;i++){
		        if(nums[i]>nums[i-1]&&f==0){
		            ans1++;
		            f=1;
		        }
		        else if(nums[i]<nums[i-1]&&f==1){
		            ans1++;
		            f=0;
		        }
		    }
		    f=1;
		    for(int i=1;i<n;i++){
		        if(nums[i]>nums[i-1]&&f==0){
		            ans2++;
		            f=1;
		        }
		        else if(nums[i]<nums[i-1]&&f==1){
		            ans2++;
		            f=0;
		        }
		    }
		    return 1+max(ans1,ans2);
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.AlternatingaMaxLength(nums);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends