class Solution {
public:
    bool f=0;
    bool vis[50005];
    void dfs(int st,vector<int>& arr){
        vis[st]=1;
        if(arr[st]==0){
            f=1;
            return;
        }
        int le=st-arr[st],ri=st+arr[st],n=arr.size();
        if(le>=0&&le<n&&vis[le]==0)dfs(le,arr);
        if(ri>=0&&ri<n&&vis[ri]==0)dfs(ri,arr);
    }
    bool canReach(vector<int>& arr, int start) {
        dfs(start,arr);
        return f;
    }
};