class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans;
        for(int i=1;i<=n;i++){
            string k;
            if(i%3==0)k+="Fizz";
            if(i%5==0)k+="Buzz";
            if(k.size()==0)k+=to_string(i);
            ans.push_back(k);
        }
        return ans;
    }
};