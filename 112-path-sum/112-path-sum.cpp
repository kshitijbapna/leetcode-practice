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
    bool f=0;
    void help(TreeNode* root,int t,int sum){
        // if(root==NULL&&sum==t)f=1;
        if(root==NULL)return;
        sum+=root->val;
        if(root->left==NULL&&root->right==NULL&&sum==t)f=1;
        help(root->left,t,sum);
        help(root->right,t,sum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL)return 0;
        help(root,targetSum,0);
        return f;
    }
};