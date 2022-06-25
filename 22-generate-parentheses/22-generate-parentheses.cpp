class Solution {
public:
    vector<string> ans;
    void solve(int st,int n,string s,int done){
        if(s.size()==2*n){
            ans.push_back(s);
            return;
        }
        if(st+1<=n-done){
            st++;
            s+='(';
            solve(st,n,s,done);
            st--;
            s.pop_back();
        }
        if(st>0){
            st--;
            s+=')';
            done++;
            solve(st,n,s,done);
            
        }
    }
    vector<string> generateParenthesis(int n) {
        string s;
        solve(0,n,s,0);
        return ans;
    }
};