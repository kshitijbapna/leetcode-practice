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
    void help(TreeNode* root,TreeNode*prev,int low,int high){
        if(root==NULL)return;
        if(root->val<low){
            prev->left=root->right;
            help(prev->left,prev,low,high);
            return;
        }
        else if(root->val>high){
            prev->right=root->left;
            help(prev->right,prev,low,high);
            return;
        }
        help(root->left,root,low,high);
        help(root->right,root,low,high);
    }
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        int c=10;
        int xx=root->val;
        while(1){
            while(root!=NULL&&root->val<low){
                root=root->right;
                // c++;
            }
            while(root!=NULL&&root->val>high){
                root=root->left;
                // c++;
            }
            if(root==NULL)break;
            if(xx==root->val)break;
            xx=root->val;
            // if(c==0)break;
        }
        if(root==NULL)return NULL;

        help(root->left,root,low,high);
        help(root->right,root,low,high);
        return root;
    }
};