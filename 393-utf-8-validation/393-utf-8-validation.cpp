class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int cnt=0;
        for(auto x : data){
            if(x>>3==0b11110)cnt+=3;
            else if(x>>4==0b1110)cnt+=2;
            else if(x>>5==0b110)cnt++;
            else if(x>>6==0b10)cnt--;
            else if(x>>7==0b1)return 0;
        }
        return cnt==0;
    }
};