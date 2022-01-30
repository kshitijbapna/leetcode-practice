#include<bits/stdc++.h>
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        reverse(nums.begin(),nums.end());
        int n=nums.size();
        k%=n;  
        int gc=__gcd(n,k);
        for(int i=0;i<gc;i++){
            int temp=nums[i];
            int j=i;
            while(1){
                int x=j+k;
                if(x>=n)x-=n;
                if(x==i)break;
                nums[j]=nums[x];
                j=x;
            }
            nums[j]=temp;
        }
        reverse(nums.begin(),nums.end());
    }   
};