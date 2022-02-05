class Solution {
public:
    int cost(int st,int mo,int pu,vector<int> v){
        int ans=0;
        if(v[0]==0&&v[1]==0&&v[2]==0){
            if(st==v[3]){
                ans+=pu;
            }
            else{
                ans+=(mo+pu);
            }
        }  
        else if(v[0]==0&&v[1]==0){
            if(st==v[2]){
                ans+=pu;
                if(v[2]==v[3])ans+=pu;
                else ans+=pu+mo;
            }
            else{
                ans+=(mo+pu);
                if(v[2]==v[3])ans+=pu;
                else ans+=(mo+pu);
            }
        }
        else if(v[0]==0){
            if(st==v[1]){
                ans+=pu;
                if(v[1]==v[2])ans+=pu;
                else ans+=pu+mo;
                if(v[2]==v[3])ans+=pu;
                else ans+=pu+mo;
            }
            else{
                ans+=(mo+pu);
                if(v[1]==v[2])ans+=pu;
                else ans+=(mo+pu);
                if(v[2]==v[3])ans+=pu;
                else ans+=(mo+pu);
            }
        }
        else{
            if(st==v[0]){
                ans+=pu;
                if(v[0]==v[1])ans+=pu;
                else ans+=(pu+mo);
                if(v[1]==v[2])ans+=pu;
                else ans+=(pu+mo);
                if(v[2]==v[3])ans+=pu;
                else ans+=(pu+mo);
            }
            else{
                ans+=(pu+mo);
                if(v[0]==v[1])ans+=pu;
                else ans+=(pu+mo);
                if(v[1]==v[2])ans+=pu;
                else ans+=(pu+mo);
                if(v[2]==v[3])ans+=pu;
                else ans+=(pu+mo);
            }
        }
        return ans;
    }
    int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds) {
        int se=targetSeconds,mi=0,ans=INT_MAX;
        for(int i=0;i<1000;i++){
            se=targetSeconds-60*i;
            mi=i;
            if(se<=99&&se>=0&&mi>=0&&mi<=99){
                vector<int> v(4);
                v[0]=mi/10;
                v[1]=mi%10;
                v[2]=se/10;
                v[3]=se%10;
                
                int xx=cost(startAt,moveCost,pushCost,v);
                
                // for(int i=0;i<4;i++)cout<<v[i]<<" ";
                // cout<<"\n";
                // cout<<xx<<"\n";
                
                ans=min(ans,xx);
            }
        }
        return ans;
    }
};