class Solution {
public:
    long long smallestNumber(long long num) {
        bool f=0;
        if(num==0)return 0;
        long long ans;
        if(num<0){
            f=1;
            num*=-1;
        }
        if(!f){
            string s=to_string(num);
            sort(s.begin(),s.end());
            int i=0;
            while(s[i]=='0')i++;
            swap(s[0],s[i]);
            ans=stoll(s);
        }
        else{
            string s=to_string(num);
            sort(s.rbegin(),s.rend());
            ans=stoll(s);
            ans*=-1;
        }
        return ans;
    }
};