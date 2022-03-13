class Solution {
public:
    bool isValid(string s) {
        stack<char> t;
        for(int i=0;i<s.size();i++){
            if(!t.empty())
            {if((s[i]==')'&&t.top()=='(')||(s[i]==']'&&t.top()=='[')||(s[i]=='}'&&t.top()=='{'))t.pop();
            else t.push(s[i]);}
            else t.push(s[i]);
        }
        if(t.empty())return 1;
        else return 0;
    }
};