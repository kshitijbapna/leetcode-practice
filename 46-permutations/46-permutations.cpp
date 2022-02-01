class Solution {
public:
    vector<vector<int>> ans;
    // void permute(vector<int> nums,int l,int r){
    //     if(l==r)v.push_back(nums);
    //     else{
    //         for(int i=l;i<=r;i++){
    //             swap(nums[l],nums[i]);
    //             permute(nums,l+1,r);
    //             swap(nums[l],nums[i]);
    //         }
    //     }
    // }
    bool next_permutation(vector<int>& v){
        int n=v.size(),i,k,l,f=0;
        for(i=n-2;i>=0;i--){
            if(v[i]<v[i+1]){
                k=i;
                break;
            }
        }
        if(i==-1)return 0;
        for(i=n-1;i>k;i--){
            if(v[k]<v[i]){
                l=i;
                break;
            }
        }
        swap(v[k],v[l]);
        sort(v.begin()+k+1,v.end());
        return 1;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        ans.push_back(nums);
        while(next_permutation(nums))ans.push_back(nums);
        return ans;
    }
};