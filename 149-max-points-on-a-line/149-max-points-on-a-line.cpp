class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        set<pair<double,double>> s;
        sort(points.begin(),points.end());
        int n=points.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(points[i][0]==points[j][0])continue;
                double num=points[i][1]-points[j][1];
                double den=points[i][0]-points[j][0];
                double m=num/den;
                double c=points[i][1]-m*points[i][0];
                s.insert({m,c});
            }
        }
        map<int,int> m;
        int ans=0;
        for(int i=0;i<n;i++){
            m[points[i][0]]++;
            ans=max(ans,m[points[i][0]]);
        }
        for(auto x : s){
            double m=x.first,c=x.second;
            int cnt=0;
            for(int i=0;i<n;i++){
                double rhs=m*points[i][0]+c;
                double lhs=points[i][1];
                if(abs(lhs-rhs)<=0.000001)cnt++;
            }
            ans=max(ans,cnt);
        }
        return ans;
    }
};