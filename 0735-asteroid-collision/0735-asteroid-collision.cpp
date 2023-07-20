class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        stack<int> st;
        for(auto asteroid : asteroids){
            if(asteroid>0){
                st.push(asteroid);
            }
            else{
                bool eq=0;
                while(st.size()>0&&-asteroid>=st.top()){
                    if(st.top()==-asteroid){
                        eq=1;
                        st.pop();
                        break;
                    }
                    st.pop();
                }
                if(st.size()==0&&eq==0)ans.push_back(asteroid);
            }
        }
        vector<int> tmp;
        while(st.size()>0){
            tmp.push_back(st.top());
            st.pop();
        }
        reverse(tmp.begin(),tmp.end());
        for(auto x : tmp)ans.push_back(x);
        return ans;
    }
};