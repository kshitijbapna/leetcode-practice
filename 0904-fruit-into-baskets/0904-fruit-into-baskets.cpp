class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        map<int,int> cnt;
        int i=0,j=0,ans=0,n=fruits.size();
        while(i<n){
            while(j<n&&cnt.size()<=2){
                cnt[fruits[j]]++;
                j++;
            }
            
            int tmp=0;
            for(auto x : cnt){
                tmp+=x.second;
            }
            
            if(cnt.size()==3){
                tmp--;
                while(cnt.size()==3){
                    cnt[fruits[i]]--;
                    if(cnt[fruits[i]]==0)cnt.erase(fruits[i]);
                    i++;
                }
            }
            else{
                cnt[fruits[i]]--;
                i++;
                
            }
            ans=max(ans,tmp);
        }
        return ans;
    }
};