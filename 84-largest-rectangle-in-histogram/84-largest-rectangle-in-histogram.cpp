class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int area=0,n=h.size();
        stack<int> s;
        vector<int> l(n),r(n);
        for(int i=0;i<n;i++){
            while(!s.empty()&&h[s.top()]>=h[i]){
                s.pop();
            }
            if(s.empty())l[i]=0;
            else l[i]=s.top()+1;
            s.push(i);
        }
        while(!s.empty())s.pop();
        for(int i=n-1;i>=0;i--){
            while(!s.empty()&&h[s.top()]>=h[i]){
                s.pop();
            }
            if(s.empty())r[i]=n-1;
            else r[i]=s.top()-1;
            s.push(i);
        }
        
        for(int i=0;i<n;i++){
            // cout<<l[i]<<" "<<r[i]<<" "<<h[i]<<"\n";
            area=max(area,h[i]*(r[i]-l[i]+1));
        }
        return area;
    }
};