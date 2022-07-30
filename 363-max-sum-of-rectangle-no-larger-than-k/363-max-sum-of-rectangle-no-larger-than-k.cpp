class Solution {
public:
    int maX(vector<int> &arr, int K)
    {
        int N=arr.size();
        // Hash to lookup for value (cum_sum - K)
        set<int> cum_set;
        cum_set.insert(0);

        int max_sum = INT_MIN, cSum = 0;

        for (int i = 0; i < N; i++) {

            // getting cumulative sum from [0 to i]
            cSum += arr[i];

            // lookup for upperbound
            // of (cSum-K) in hash
            set<int>::iterator sit
                = cum_set.lower_bound(cSum - K);

            // check if upper_bound
            // of (cSum-K) exists
            // then update max sum
            if (sit != cum_set.end())

                max_sum = max(max_sum, cSum - *sit);

            // insert cumulative value in hash
            cum_set.insert(cSum);
        }

        // return maximum sum
        // lesser than K
        return max_sum;
    }
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int R=matrix.size(),C=matrix[0].size();
        vector<vector<int>> y=matrix;
        for(int i=1;i<R;i++){
            for(int j=0;j<C;j++){
                y[i][j]+=y[i-1][j];
            }
        }
        int ans=INT_MIN;
        for(int r1=0;r1<R;r1++){
            for(int r2=r1;r2<R;r2++){
                vector<int> arr;
                if(r1==0){
                    for(int i=0;i<C;i++)arr.push_back(y[r2][i]);
                }
                else{
                    for(int i=0;i<C;i++)arr.push_back(y[r2][i]-y[r1-1][i]);
                }
                ans=max(ans,maX(arr,k));
            }
        }
        return ans;
    }
};