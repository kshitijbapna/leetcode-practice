class Solution {
public:
    vector<vector<int>> ans;
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
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        ans.push_back(nums);
        while(next_permutation(nums))ans.push_back(nums);
        return ans;
    }
};