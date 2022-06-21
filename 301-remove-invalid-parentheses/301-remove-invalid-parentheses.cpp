class Solution {
public:
    bool valid(string s){
        int st=0;
        for(int i=0;i<s.size();i++)if(s[i]=='(')st++;
        else if(s[i]==')'){
            st--;
            if(st<0)return 0;
        }
        if(st!=0)return 0;
        return 1;
    }
    vector<string> removeInvalidParentheses(string s) {
        queue<string> q;
        map<string,int> m;
        set<string> ss;
        q.push(s);
        // int yy=10;
        while(!q.empty()){
            // yy--;
            // if(!yy)break;
            int sz=q.size();
            while(sz--){
                string x=q.front();
                q.pop();
                // cout<<x<<"\n";
                if(valid(x))ss.insert(x);
                if(ss.size()==0)
                for(int i=0;i<x.size();i++){
                    string y=x;
                    if(y[i]=='('||y[i]==')'){
                        y.erase(y.begin()+i);
                    }
                    if(m[y]==0){
                        // cout<<y<<" ";
                        m[y]=1;
                        q.push(y);
                    }
                }
            }
            if(ss.size()>0)break;
        }
        // cout<<ss.size()<<"\n";
        return vector<string>{ss.begin(),ss.end()};
    }
};