class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int carry=0,n=num.size(),curr=n-1;
        while(curr>=0||k>0){
            if(curr<0)break;
            num[curr]+=carry+k%10;
            k/=10;
            carry=num[curr]/10;
            // cout<<num[curr]<<" "<<carry<<"\n";
            num[curr]%=10;
            curr--;
        }
        while(carry!=0){
            int x=carry+k%10;
            k/=10;
            carry=x/10;
            x%=10;
            num.insert(num.begin(),x);
        }
        while(k>0){
            num.insert(num.begin(),k%10);
            k/=10;
        }
        return num;
    }
};