class Solution {
public:
    bool sumGame(string num) {
        int q1=0,q2=0,s1=0,s2=0;
        for(int i=0;i<num.size();i++){
            if(i<num.size()/2){
                if(num[i]=='?')q1++;
                else s1+=num[i]-'0';
            }
            else{
                if(num[i]=='?')q2++;
                else s2+=num[i]-'0';
            }
        }
        int s2r=s2,s1r=s1,q1r=q1,q2r=q2;
        if((q1+q2)%2)return 1;
        int k=0,kk=0;
        while(q1||q2){
            k++;
            if(q1>0&&q2>0){
                if(k%2){
                    s2+=9;
                    q2--;
                }
                else{
                    s1+=9;
                    q1--;
                }
            }
            else if(q1>0){
                if(k%2){
                    q1--;
                }
                else{
                    s1+=9;
                    q1--;
                }
            }
            else if(q2>0){
                if(k%2){
                    s2+=9;
                    q2--;
                }
                else{
                    q2--;
                }
            }
        }
        int kr=0,kkr=0;
        while(q1r||q2r){
            kr++;
            if(q1r>0&&q2r>0){
                if(kr%2){
                    s1r+=9;
                    q1r--;
                }
                else{
                    s2r+=9;
                    q2r--;
                }
            }
            else if(q2r>0){
                if(kr%2){
                    q2r--;
                }
                else{
                    s2r+=9;
                    q2r--;
                }
            }
            else if(q1r>0){
                if(kr%2){
                    s1r+=9;
                    q1r--;
                }
                else{
                    q1r--;
                }
            }
        }
        // cout<<s1<<" "<<s2<<" "<<s1
        if(s1!=s2)return 1;
        if(s1r!=s2r)return 1;
        return 0;
    }
};