class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<string> v;
        for(long long i=0;i<30;i++){
            v.push_back(to_string(1ll<<i));
            sort(v[v.size()-1].begin(),v[v.size()-1].end());
        }
        // for(int i=0;i<30;i++)cout<<v[i]<<" ";
        string vv=to_string(n);
        sort(vv.begin(),vv.end());
        for(int i=0;i<v.size();i++){
            if(vv==v[i])return 1;
        }
        return 0;
    }
};