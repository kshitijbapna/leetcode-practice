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
    int sum=0;
    void inorder1(TreeNode* root){
        if(root==NULL)return;
        inorder1(root->left);
        sum+=root->val;
        inorder1(root->right);
    }
    void inorder2(TreeNode* root){
        if(root==NULL)return;
        inorder2(root->left);
        int tmp=root->val;
        root->val=sum;
        sum=root->val-tmp;
        inorder2(root->right);
    }
    TreeNode* convertBST(TreeNode* root) {
        inorder1(root);
        cout<<sum;
        inorder2(root);
        return root;
    }
};