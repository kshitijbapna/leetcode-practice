class Solution {
public:
    int subWithSum(vector<int> &arr,int sum){
        unordered_map<int,int> prevSum;
        int res=0,currSum=0;
        for(int i=0;i<arr.size();i++){
            currSum+=arr[i];
            if(currSum==sum)res++;
            if(prevSum.find(currSum-sum)!=prevSum.end()){
                res+=prevSum[currSum-sum];
            }
            prevSum[currSum]++;
        }
        return res;
    }
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m=matrix[0].size(),n=matrix.size();
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                matrix[i][j]+=matrix[i-1][j];
            }
        }
        int ans=0;
        for(int r1=0;r1<n;r1++){
            for(int r2=r1;r2<n;r2++){
                vector<int> arr;
                if(r1==0){
                    for(int i=0;i<m;i++)arr.push_back(matrix[r2][i]);
                }
                else{
                    for(int i=0;i<m;i++)arr.push_back(matrix[r2][i]-matrix[r1-1][i]);
                }
                ans+=subWithSum(arr,target);
            }
        }
        return ans;
    }
};