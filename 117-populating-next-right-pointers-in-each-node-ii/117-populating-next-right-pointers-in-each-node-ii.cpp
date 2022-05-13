/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL)return NULL;
        queue<Node*> q;
        q.push(root);
        while(q.size()>0){
            int x=q.size();
            Node* prev=q.front();
            q.pop();
            if(prev->left!=NULL)
            q.push(prev->left);
            if(prev->right!=NULL)
            q.push(prev->right);
            x--;
            while(x--){
                Node* curr=q.front();
                if(curr->left!=NULL)
                q.push(curr->left);
                if(curr->right!=NULL)
                q.push(curr->right);
                q.pop();
                prev->next=curr;
                prev=curr;
            }
        }
        return root;
    }
};