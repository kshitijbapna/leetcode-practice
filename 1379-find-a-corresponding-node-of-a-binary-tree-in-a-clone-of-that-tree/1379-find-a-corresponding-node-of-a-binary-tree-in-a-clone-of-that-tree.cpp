/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* ans;
    void help(TreeNode* oroot,TreeNode* croot,TreeNode* ta){
        if(oroot==NULL)return;
        if(oroot==ta)ans=croot;
        help(oroot->left,croot->left,ta);
        help(oroot->right,croot->right,ta);
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        help(original, cloned, target);
        return ans;
    }
};