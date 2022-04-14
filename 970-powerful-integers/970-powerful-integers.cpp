class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        if(bound==0)return {};
        vector<int> ans;
        if(x==1&&y==1){
            if(bound<2)return {};
            ans.push_back(2);
            return ans;
        }
        if(x==1){
            int a=log(bound)/log(y);
            int i=0;
            while(pow(y,i)+1<=bound){
                ans.push_back(pow(y,i)+1);
                i++;
            }
            return ans;
        }
        if(y==1){
            int a=log(bound)/log(x);
            int i=0;
            while(pow(x,i)+1<=bound){
                ans.push_back(pow(x,i)+1);
                i++;
            }
            return ans;
        }
        int a=log(bound)/log(x),b=log(bound)/log(y);
        set<int> s;
        for(int i=0;i<=a+1;i++){
            for(int j=0;j<=b+1;j++){
                long long k=pow(x,i)+pow(y,j);
                if(k<=bound&&s.count(k)==0){
                    ans.push_back(k);
                    s.insert(k);
                }
            }
        }
        return ans;
    }
};