class Solution {
public:
    static bool cmp(vector<int>& a,vector<int>& b){
        if(a[0]==b[0])return a[1]>b[1];
        return a[0]<b[0];
    }
    int LongestIncreasingSubsequenceLength(std::vector<int>& v)
    {
        if (v.size() == 0) // boundary case
            return 0;

        std::vector<int> tail(v.size(), 0);
        int length = 1; // always points empty slot in tail

        tail[0] = v[0];

        for (int i = 1; i < v.size(); i++) {

            // Do binary search for the element in
            // the range from begin to begin + length
            auto b = tail.begin(), e = tail.begin() + length;
            auto it = lower_bound(b, e, v[i]);

            // If not present change the tail element to v[i]
            if (it == tail.begin() + length)
                tail[length++] = v[i];
            else
                *it = v[i];
        }

        return length;
    }
    int maxEnvelopes(vector<vector<int>>& e) {
        vector<int> x;
        sort(e.begin(),e.end(),cmp);
        for(int i=0;i<e.size();i++)x.push_back(e[i][1]);
        return LongestIncreasingSubsequenceLength(x);
    }
};