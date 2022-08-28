class Solution {
public:
    map<int,multiset<int>> mp;
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mp[i-j].insert(mat[i][j]);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int curr=*mp[i-j].begin();
                mat[i][j]=curr;
                mp[i-j].erase(mp[i-j].find(curr));
            }
        }
        return mat;
    }
};