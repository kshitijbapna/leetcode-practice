class Solution {
public:
    int minDeletions(string s) {
        vector<int> v(26);
        for(int i=0;i<s.size();i++)v[s[i]-'a']++;
        priority_queue<int> pq;
        for(int i=0;i<26;i++)if(v[i]!=0)pq.push(v[i]);
        int ans=0;
        while(pq.size()>1){
            int x=pq.top();
            pq.pop();
            int y=pq.top();
            pq.pop();
            if(x==y){
                x--;
                if(x!=0)
                pq.push(x);
                pq.push(y);
                ans++;
            }
            else if(x!=y){
                pq.push(y);
            }
        }
        return ans;
    }
};