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
    void help(TreeNode* root,string s){
        if(root==NULL)
            return;
        s+=to_string(root->val);
        if(root->left==NULL&&root->right==NULL){
            ans+=stoi(s);
            return;
        }
        help(root->left,s);
        help(root->right,s);
    }
    int sumNumbers(TreeNode* root) {
        help(root,"");
        return ans;
    }
};