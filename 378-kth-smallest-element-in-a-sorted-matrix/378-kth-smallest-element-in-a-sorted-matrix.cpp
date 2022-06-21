class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        long long l=-1e9,r=1e9;
        while(l<=r){
            long long mid=(l+r)/2;
            int pos=0;
            for(int i=0;i<matrix.size();i++){
                pos+=upper_bound(matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin();
            }
            if(pos>k-1){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return l;
    }
};