class Solution {
public:
    int subWithSum(vector<int> &arr,int sum){
        unordered_map<int,int> prev_sum;
        int res=0,currSum=0;
        for(int i=0;i<arr.size();i++){
            currSum+=arr[i];
            if(currSum==sum)res++;
            if(prev_sum.find(currSum-sum)!=prev_sum.end()){
                res+=prev_sum[currSum-sum];
            }
            prev_sum[currSum]++;
        }
        return res;
    }
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        vector<vector<int>> cpy=matrix;
        int m=matrix[0].size(),n=matrix.size();
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                cpy[i][j]+=cpy[i-1][j];
            }
        }
        int ans=0;
        for(int r1=0;r1<n;r1++){
            for(int r2=r1;r2<n;r2++){
                vector<int> arr;
                if(r1==0){
                    for(int i=0;i<m;i++)arr.push_back(cpy[r2][i]);
                }
                else{
                    for(int i=0;i<m;i++)arr.push_back(cpy[r2][i]-cpy[r1-1][i]);
                }
                ans+=subWithSum(arr,target);
            }
        }
        return ans;
    }
};