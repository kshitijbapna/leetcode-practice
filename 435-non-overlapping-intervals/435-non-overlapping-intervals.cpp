class Solution {
public:
    static bool cmp(vector<int>& a,vector<int> &b){
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int ans=-1;
        sort(intervals.begin(),intervals.end(),cmp);
        vector<int> prev=intervals[0];
        for(auto interval : intervals){
            if(prev[1]>interval[0]){
                ans++;
            }
            else{
                prev=interval;
            }
        }
        return ans;
    }
};