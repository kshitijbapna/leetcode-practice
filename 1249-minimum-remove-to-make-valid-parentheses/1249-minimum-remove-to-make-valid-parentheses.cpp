class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> a;
        string ans;
        int i=0;
        while(i<s.size()){
            if(s[i]==')'){
                if(!a.empty()){
                    a.pop();
                    ans+=s[i];
                }
            }   
            else if(s[i]=='('){
                a.push(1);
                ans+=s[i];
            }
            else{
                ans+=s[i];
            }
            i++;
        }
        int k=a.size();
        int j=ans.size()-1;
        while(1){
            if(k==0)break;
            if(ans[j]=='('){
                ans.erase(ans.begin()+j);
                k--;
                if(k==0)break;
            }
            j--;
        }
        return ans;
    }
};