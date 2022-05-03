class Solution {
public:
    static bool cmp(int a,int b){
        if(a%2==0&&b%2==1)return a<b;
        return b<a;
    }
    vector<int> sortArrayByParity(vector<int>& A) {
        for (int i = 0, j = 0; j < A.size(); j++)
            if (A[j] % 2 == 0) swap(A[i++], A[j]);
        return A;
    }
};