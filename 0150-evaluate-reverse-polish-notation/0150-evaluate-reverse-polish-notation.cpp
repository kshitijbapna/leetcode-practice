class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        long long int a,b;
        stack<long long int> s;
        for(auto x : tokens){
            if(x=="+"){
                a=s.top();
                s.pop();
                b=s.top();
                s.pop();
                s.push(a+b);
            }
            else if(x=="-"){
                a=s.top();
                s.pop();
                b=s.top();
                s.pop();
                s.push(b-a);
            }
            else if(x=="*"){
                a=s.top();
                s.pop();
                b=s.top();
                s.pop();
                s.push(a*b);
            }
            else if(x=="/"){
                a=s.top();
                s.pop();
                b=s.top();
                s.pop();
                s.push(b/a);
            }
            else{
                s.push(stoll(x));
            }
        }
        return s.top();
    }
};