class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        map<int,int> m;
        for(int i=0;i<deck.size();i++){
            m[deck[i]]++;
        }
        int xx=-1;
        for(auto x: m){
            if(xx==-1){
                xx=x.second;
            }
            else{
                xx=__gcd(xx,x.second);
            }
        }
        if(xx>1)return 1;
        return 0;
    }
};