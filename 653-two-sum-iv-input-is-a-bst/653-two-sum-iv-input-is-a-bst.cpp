/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    set<int> s;
    bool f=0;
    void inorder(TreeNode* root,int k){
        if(!root)return;
        inorder(root->left,k);
        if(s.find(k-root->val)!=s.end())f=1;
        s.insert(root->val);
        inorder(root->right,k);
    }
    bool findTarget(TreeNode* root, int k) {
        inorder(root,k);
        return f;
    }
};