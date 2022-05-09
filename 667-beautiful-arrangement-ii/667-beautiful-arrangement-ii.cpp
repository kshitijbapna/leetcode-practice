class Solution {
public:
    vector<int> constructArray(int n, int k) {
        // 1, k+1, 2, k, 3, k-1 ...;
// The distance of this sequence is k, k-1, k-2, ..., 2, 1
        int l = 1, r = k+1;
        vector<int> ans;
        while (l <= r) {
            ans.push_back(l++);
            if (l <= r) ans.push_back(r--);
        }
        for (int i = k+2; i <= n; i++)
            ans.push_back(i);
        return ans;
    }
};