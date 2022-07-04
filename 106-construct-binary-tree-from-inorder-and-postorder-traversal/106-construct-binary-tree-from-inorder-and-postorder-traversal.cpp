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
    TreeNode* help(vector<int>& inorder,vector<int>& postorder,int leftin,int rightin,int leftp,int rightp){
        if(leftin>rightin)return NULL;
        if(leftp>rightp)return NULL;
        TreeNode* root=new TreeNode(postorder[rightp]);
        int index=m[postorder[rightp]];
        int k=index-leftin;
        root->left=help(inorder,postorder,leftin,index-1,leftp,leftp+k-1);
        root->right=help(inorder,postorder,index+1,rightin,leftp+k,rightp-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        for(int i=0;i<n;i++)m[inorder[i]]=i;
        return help(inorder,postorder,0,n-1,0,n-1);
    }
};