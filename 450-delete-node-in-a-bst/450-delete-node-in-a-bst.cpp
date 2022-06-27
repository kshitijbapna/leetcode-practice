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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root){
            if(key<root->val)root->left=deleteNode(root->left,key);
            else if(key>root->val)root->right=deleteNode(root->right,key);
            else{
                if(!root->left&&!root->right)return NULL;
                if(!root->left||!root->right){
                    if(root->left)return root->left;
                    return root->right;
                }
                TreeNode* tmp=root->left;
                while(tmp->right!=NULL)tmp=tmp->right;
                root->val=tmp->val;
                root->left=deleteNode(root->left,tmp->val);
            }
        }
        return root;
    }
};