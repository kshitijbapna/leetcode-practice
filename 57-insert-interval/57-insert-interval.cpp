class Solution {
public:
    bool intersect(int a,int b,int c,int d){
        if(c>=a&&d<=b)return 1;
        if(c<=a&&d>=b)return 1;
        if(c>=a&&c<=b)return 1;
        if(a>=c&&a<=d)return 1;
        return 0;
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int st=-1,en=-1;
        for(int i=0;i<intervals.size();i++){
            if(st==-1&&intersect(newInterval[0],newInterval[1],intervals[i][0],intervals[i][1])){
                st=i;
                en=i;
            }
            if(intersect(newInterval[0],newInterval[1],intervals[i][0],intervals[i][1]))en=i;
        }
        if(st==-1){
            intervals.push_back(newInterval);
            sort(intervals.begin(),intervals.end());
            return intervals;
        }
        vector<vector<int>> ans;
        int ns=min(intervals[st][0],newInterval[0]),ne=max(intervals[en][1],newInterval[1]);
        for(int i=0;i<intervals.size();i++){
            if(i==st){ans.push_back({ns,ne});continue;}
            if(i>=st&&i<=en)continue;
            else ans.push_back(intervals[i]);
        }
        return ans;
    }
};