class Solution {
public:
    int kadane(vector<int>& arr){
        int mx=0,gmx=INT_MIN;
        for(int i=0;i<arr.size();i++){
            mx+=arr[i];
            gmx=max(mx,gmx);
            if(mx<0)mx=0;
        }
        return gmx;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
    
        vector<vector<int>> x(n,vector<int>(m,0));
        for(int i=0;i<n;i++)for(int j=0;j<m;j++)x[i][j]=(matrix[i][j]=='1')?1:-100000;
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                x[i][j]+=x[i-1][j];
            }
        }
        int ans=0;
        for(int r1=0;r1<n;r1++){
            for(int r2=r1;r2<n;r2++){
                vector<int> v;
                if(r1==0){
                    for(int i=0;i<m;i++)v.push_back(x[r2][i]);
                }
                else{
                    for(int i=0;i<m;i++)v.push_back(x[r2][i]-x[r1-1][i]);
                }
                ans=max(ans,kadane(v));
            }
        }
        return ans;
    }
};