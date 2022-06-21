class Solution {
public:
    bool valid(string s){
        int st=0;
        for(int i=0;i<s.size();i++)if(s[i]=='(')st++;
        else if(s[i]==')'){
            st--;
            if(st<0)return 0;
        }
        return st==0;
    }
    vector<string> removeInvalidParentheses(string s) {
        queue<string> q;
        unordered_map<string,int> m;
        unordered_set<string> ss;
        q.push(s);
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                string x=q.front();
                q.pop();
                if(valid(x))ss.insert(x);
                if(ss.size()==0)
                for(int i=0;i<x.size();i++){
                    string y=x;
                    if(y[i]=='('||y[i]==')'){
                        y.erase(y.begin()+i);
                    }
                    if(m[y]==0){
                        m[y]=1;
                        q.push(y);
                    }
                }
            }
            if(ss.size()>0)break;
        }
        return vector<string>{ss.begin(),ss.end()};
    }
};