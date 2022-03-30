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
    int ans=0;
    void help(TreeNode* root,int an){
        if(root==NULL)
            return;
        an=an*10+root->val;
        if(root->left==NULL&&root->right==NULL){
            ans+=an;
            return;
        }
        help(root->left,an);
        help(root->right,an);
    }
    int sumNumbers(TreeNode* root) {
        help(root,0);
        return ans;
    }
};