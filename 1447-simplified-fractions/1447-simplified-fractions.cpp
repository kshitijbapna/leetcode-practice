class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        set<string> s;
        for(int de=2;de<=n;de++){
            for(int nu=1;nu<de;nu++){
                int x=__gcd(nu,de),nux=nu/x,dex=de/x;
                string xx=to_string(nux)+"/"+to_string(dex);
                s.insert(xx);
            }
        }
        vector<string> ans(s.begin(),s.end());
        return ans;
    }
};