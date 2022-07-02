class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        if(a.find(b)!=string::npos)return 1;
        int l=1,r=2*b.size()/a.size(),f=0;
        r=max(r,3);
        
        while(l<=r){
            int mid=(l+r)/2,tmp=mid;
            string s;
            while(tmp--)s+=a;
            if(s.find(b)!=string::npos){
                r=mid-1;
                f=1;
            }
            else{
                l=mid+1;
            }
        }
        if(!f)return -1;
        return l;
    }
};