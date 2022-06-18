class Solution {
public:
    bool isHappy(int n) {
        set<int> s;
        while(1){
            int tmp=n,k=0;
            while(tmp){
                k+=(tmp%10)*(tmp%10);
                tmp/=10;
            }
            // cout<<k<<" ";
            if(s.find(k)!=s.end())return 0;
            if(k==1)return 1;
            s.insert(k);
            n=k;
        }
        return 0;
    }
};