class Solution {
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        vector<int> num1=nums1,num2=nums2;
        vector<int> diff1(n),diff2(n);
        for(int i=0;i<n;i++){
            diff1[i]=nums1[i]-nums2[i];
            diff2[i]=nums2[i]-nums1[i];
        }
        int min_end=INT_MAX,min_so=INT_MAX,l=-1,r=0,lm=-1,rm=-1;
        for(int i=0;i<n;i++){
            if(min_end>0){
                min_end=diff1[i];
                l=i,r=i;
            }
            else{
                min_end+=diff1[i];
                r=i;
            }
            if(min_so>min_end){
                min_so=min_end;
                lm=l,rm=r;
            }
        }
        if(min_so<0){
            for(int i=lm;i<=rm;i++)swap(nums1[i],nums2[i]);
        }
        int ans1=0;
        for(int i=0;i<n;i++){
            ans1+=nums1[i];
        }
        
        
        int min_end1=INT_MAX,min_so1=INT_MAX,l1=-1,r1=0,lm1=-1,rm1=-1;
        for(int i=0;i<n;i++){
            if(min_end1>0){
                min_end1=diff2[i];
                l1=i,r1=i;
            }
            else{
                min_end1+=diff2[i];
                r1=i;
            }
            if(min_so1>min_end1){
                min_so1=min_end1;
                lm1=l1,rm1=r1;
            }
        }
        if(min_so1<0){
            for(int i=lm1;i<=rm1;i++)swap(num1[i],num2[i]);
        }
        int ans2=0;
        for(int i=0;i<n;i++){
            ans2+=num2[i];
        }
        return max(ans1,ans2);
    }
};