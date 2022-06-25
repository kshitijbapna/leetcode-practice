class Solution {
public:
    string addStrings(string num1, string num2) {
        if(num1.size()>num2.size())swap(num1,num2);
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        string ans=num2;
        int c=0,i=0;
        for(i=0;i<num1.size();i++){
            int k=num1[i]+num2[i]-2*'0'+c;
            c=0;
            if(k>9)c=1;
            k%=10;
            ans[i]=k+'0';
        }
        while(i<num2.size()){
            int k=num2[i]-'0'+c;
            c=0;
            if(k>9)c=1;
            k%=10;
            ans[i]=k+'0';
            i++;
        }
        if(c==1)ans+='1';
        reverse(ans.begin(),ans.end());
        return ans;
    }
};