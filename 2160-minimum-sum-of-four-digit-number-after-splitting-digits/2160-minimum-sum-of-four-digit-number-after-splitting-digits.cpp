class Solution {
public:
    int minimumSum(int num) {
        
        int ans=INT_MAX;
        string s=to_string(num);
        sort(s.begin(),s.end());
        do{
            string a=s.substr(0,1),b=s.substr(1,3),c=s.substr(0,2),d=s.substr(2,2),e=s.substr(0,3),f=s.substr(3,1);
            sort(b.begin(),b.end());
            sort(c.begin(),c.end());
            sort(d.begin(),d.end());
            sort(e.begin(),e.end());
            ans=min(ans,stoi(a)+stoi(b));
            ans=min(ans,stoi(d)+stoi(c));
            ans=min(ans,stoi(e)+stoi(f));
        }while(next_permutation(s.begin(),s.end()));
        return ans;
    }
};