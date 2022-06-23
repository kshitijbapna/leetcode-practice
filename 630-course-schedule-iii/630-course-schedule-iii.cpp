class Solution {
public:
    static bool cmp(vector<int> a,vector<int> b){
        if(a[1]==b[1])return a[0]<b[0];
        return a[1]<b[1];
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),cmp);
        priority_queue<int> q;
        int sum=0;
        for(auto i : courses){
            sum+=i[0];
            q.push(i[0]);
            if(sum>i[1]){
                sum-=q.top();
                q.pop();
            }
        }
        return q.size();
    }
};