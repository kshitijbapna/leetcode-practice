class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        
        int n=temp.size();
        stack<int> s;
        s.push(n-1);
        vector<int> ans(n);
        for(int i=n-2,k;i>=0;i--){
            k=temp[i];
            while(s.size()&&k>=temp[s.top()])s.pop();
            if(s.size())ans[i]=s.top()-i;
            s.push(i);
        }
        return ans;
    }
};