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
    TreeNode* curr;
    void inor(TreeNode *root){
        if(root==NULL)return;
        inor(root->left);
        root->left=NULL;
        curr=curr->right=root;
        inor(root->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* dum=new TreeNode(0);
        curr=dum;
        inor(root);
        return dum->right;
    }
};