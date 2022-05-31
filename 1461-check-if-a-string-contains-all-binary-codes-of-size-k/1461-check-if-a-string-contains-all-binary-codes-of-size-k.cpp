class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(k>s.size())return 0;
        int x=0;
        for(int i=0;i<k;i++){
            x+=pow(2,k-i-1)*(s[i]-'0');   
        }
        set<int> ss;
        ss.insert(x);
        for(int i=1;i<=s.size()-k;i++){
            x*=2;
            x-=pow(2,k)*(s[i-1]-'0');
            x+=(s[i+k-1]-'0');
            ss.insert(x);
        }
        return ss.size()==pow(2,k);
    }
};