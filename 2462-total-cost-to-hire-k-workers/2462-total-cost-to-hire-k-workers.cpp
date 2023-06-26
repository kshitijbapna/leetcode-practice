class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int c) {
        set<pair<int,int>> st1,st2;
        set<int> done;
        long long int n=costs.size(),ans=0;
        for(int i=0;i<c;i++){
            st1.insert({costs[i],i});
        }
        for(int i=n-c;i<n;i++){
            st2.insert({costs[i],i});
        }
        int l=c,r=n-c-1;
        while(k--){
            pair<int,int> p1=*st1.begin(),p2=*st2.begin();
            if(p1.first<=p2.first){
                st1.erase(st1.find(p1));
                done.insert(p1.second);
                while(done.find(l)!=done.end())l++;
                if(l<n){
                    st1.insert({costs[l],l});
                    l++;
                }
                if(st2.find(p1)!=st2.end()){
                    st2.erase(st2.find(p1));
                    while(done.find(r)!=done.end())r--;
                    if(r>=0){
                        st2.insert({costs[r],r});
                        r--;
                    }
                }
                ans+=p1.first;
                // cout<<p1.first<<" "<<p1.second<<"\n";
            }
            else{
                st2.erase(st2.find(p2));
                done.insert(p2.second);
                while(done.find(l)!=done.end())l++;
                while(done.find(r)!=done.end())r--;
                if(r>=0){
                    st2.insert({costs[r],r});
                    r--;
                }
                if(st1.find(p2)!=st1.end()){
                    st1.erase(st1.find(p2));
                    if(l<n){
                        st1.insert({costs[l],l});
                        l++;
                    }
                }
                ans+=p2.first;
                // cout<<p2.first<<" "<<p2.second<<"\n";
            }
        }
        return ans;
    }
};