/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL)return NULL;
        Node *temp=head;
        map<Node*,int> m;
        int i=0;
        while(temp){
            m[temp]=i;
            i++;
            temp=temp->next;
        }
        vector<Node*> xx;
        for(auto x:m){
            Node* a=new Node(x.first->val);
            xx.push_back(a);
        }
        for(auto x:m){
            if(x.first->next==NULL)xx[x.second]->next=NULL;
            else xx[x.second]->next=xx[m[x.first->next]];
            if(x.first->random==NULL)xx[x.second]->random=NULL;
            else xx[x.second]->random=xx[m[x.first->random]];
        }
        return xx[0];
    }
};