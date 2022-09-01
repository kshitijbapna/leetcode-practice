#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key

class RandomizedSet {
public:
    pbds s;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(s.find(val)!=s.end())return 0;
        s.insert(val);
        return 1;
    }
    
    bool remove(int val) {
        if(s.find(val)==s.end())return 0;
        s.erase(s.find(val));
        return 1;
    }
    
    int getRandom() {
        int sz=s.size();
        int y=rand()%sz;
        return *s.find_by_order(y);
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */