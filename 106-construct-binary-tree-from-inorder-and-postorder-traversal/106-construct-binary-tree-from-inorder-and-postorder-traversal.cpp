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
    int index;
    unordered_map<int,int> m;
    TreeNode* help(vector<int>& inorder,vector<int>& postorder,int left,int right){
        if(left>right)return NULL;
        TreeNode* root=new TreeNode(postorder[index--]);
        int inorder_index=m[root->val];
        
        
        root->right=help(inorder,postorder,inorder_index+1,right);
        root->left=help(inorder,postorder,left,inorder_index-1);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        index=postorder.size()-1;
        for(int i=0;i<inorder.size();i++)
            m[inorder[i]]=i;
        return help(inorder,postorder,0,inorder.size()-1);
    }
};