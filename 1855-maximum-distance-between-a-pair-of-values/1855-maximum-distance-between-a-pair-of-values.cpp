class Solution {
public:
    int maxDistance(vector<int>& A, vector<int>& B) {
        int i = 0, j = 0, res = 0, n = A.size(), m = B.size();
        while (i < n && j < m) {
            if (A[i] > B[j])
                i++;
            else
                res = max(res, j++ - i);
        }
        return res;
    }
};