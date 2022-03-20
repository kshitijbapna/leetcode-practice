class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>&B) {
        vector<int> cA(7), cB(7), s(7);
        int n = A.size();
        for (int i = 0; i < n; ++i) {
            cA[A[i]]++;
            cB[B[i]]++;
            if (A[i] == B[i])
                s[A[i]]++;
        }
        for (int i  = 1; i < 7; ++i)
            if (cA[i] + cB[i] - s[i] == n)
                return n - max(cA[i], cB[i]);
        return -1;
    }
};