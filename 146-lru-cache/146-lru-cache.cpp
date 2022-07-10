class Node {
public:
    int val;
    Node *prev;
    Node *next;
    Node(int val){
        this->val=val;
        this->prev=NULL;
        this->next=NULL;
    }
};
class LRUCache {
public:
    map<int,pair<int,Node*>> m;
    int mx=0,sz=0;
    Node *head=NULL,*tail=NULL;
    LRUCache(int capacity) {
        mx=capacity;
    }
    void print(Node *head){
        while(head){
            cout<<head->val<<" ";
            head=head->next;
        }
        cout<<"\n";
    }
    int get(int key) {
        if(m.find(key)!=m.end()){
            Node *x=m[key].second;
            if(mx==1){
                return m[head->val].first;
            }
            if(x==head){
                
            }
            else if(x==tail){
                x->prev->next=NULL;
                tail=x->prev;
                x->prev=NULL;
                x->next=head;
                head->prev=x;
                head=x;
            }
            else {
                x->next->prev=x->prev;
                x->prev->next=x->next;
                head->prev=x;
                x->next=head;
                head=x;
            }
            return m[head->val].first;
        }
        // print(head);
        return -1;
    }
    void put(int key, int value) {
        if(m.find(key)==m.end()){
            Node* x=new Node(key);
            if(mx==1){
                if(sz==1){
                    m.erase(head->val);
                }
                head=x;
                tail=x;
                m[head->val]={value,x};
                if(sz==0)sz++;
                return;
            }
            if(sz==0){
                m[key]={value,x};
                head=x;
                tail=x;
                sz++;
            }
            else if(sz==mx){
                m.erase(tail->val);
                tail=tail->prev;
                tail->next=NULL;
                x->next=head;
                head->prev=x;
                head=x;
                m[key]={value,x};
            }
            else{
                x->next=head;
                head->prev=x;
                head=x;
                m[key]={value,x};
                sz++;
            }
        }
        else{
            m[key].first=value;
            get(key);
        }
        // print(head);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */