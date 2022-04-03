class Solution {
public:
    int convertTime(string cu, string co) {
        string hrcu,hrco,micu,mico;
        hrcu+=cu[0];
        hrcu+=cu[1];
        
        micu+=cu[3];
        micu+=cu[4];

        hrco+=co[0];
        hrco+=co[1];
        
        mico+=co[3];
        mico+=co[4];
        
        int diff=0;
        if(mico>=micu){
            diff+=60*(stoi(hrco)-stoi(hrcu));
            diff+=stoi(mico)-stoi(micu);
        }
        else{
             diff+=60*(stoi(hrco)-stoi(hrcu)-1);
            diff+=60-stoi(micu)+stoi(mico);
        }
        int ans=0;
        while(diff>0){
            if(diff>=60)diff-=60;
            else if(diff>=15)diff-=15;
            else if(diff>=5)diff-=5;
            else if(diff>=1)diff-=1;
            ans++;
        }
        return ans;

    }
};