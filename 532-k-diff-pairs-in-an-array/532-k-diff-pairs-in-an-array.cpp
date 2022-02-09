class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        map<int,int> m;
        set<int> s;
        for(auto x: nums){
            m[x]++;
            s.insert(x);
        }
        int ans=0;
        for(auto x : m){
            if(s.count(x.first)&&s.count(x.first+k))             {
                if(k!=0&&m[x.first+k]>0)ans++;
                else if(k==0&&m[x.first]>1)ans++;
            }
        }
        return ans;
    }
};