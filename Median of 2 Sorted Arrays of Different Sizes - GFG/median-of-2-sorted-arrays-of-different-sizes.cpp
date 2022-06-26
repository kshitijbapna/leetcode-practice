// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    double MedianOfArrays(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int> fin;
        if(nums1.empty())fin=nums2;
        else if(nums2.empty())fin=nums1;
        else{
            int i=0,j=0,n=nums1.size(),m=nums2.size();
            while(i<n&&j<m){
                if(nums1[i]<=nums2[j]){
                    fin.push_back(nums1[i]);
                    i++;
                }
                else{
                    fin.push_back(nums2[j]);
                    j++;
                }
            }
            while(j<m){
                fin.push_back(nums2[j++]);
            }
            while(i<n){
                fin.push_back(nums1[i++]);
            }
        }
        int p=fin.size();
        
        if(p==1)return (float)fin[0];
        else if(p%2==0)return (fin[p/2]+fin[p/2-1])/2.0;
        else return (double)fin[p/2];
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i){
            cin>>array2[i];
        }
        Solution ob;
        cout<<ob.MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
}


  // } Driver Code Ends