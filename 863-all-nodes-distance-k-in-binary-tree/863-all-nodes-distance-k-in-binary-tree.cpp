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
    vector<int> ans;
    int td=0;
    TreeNode* rr=NULL;
    int dis(TreeNode *root,TreeNode *target){
        if(root==NULL)return 1e6;
        if(root==target)return 0;
        return 1+min(dis(root->left,target),dis(root->right,target));
    }
    TreeNode* lca(TreeNode* root,TreeNode* p,TreeNode* q){
        if(root==NULL)return NULL;
        if(root==p||root==q)return root;
        TreeNode* le=lca(root->left,p,q);
        TreeNode* ri=lca(root->right,p,q);
        if(le==NULL)return ri;
        if(ri==NULL)return le;
        return root;
    }
    void inorder(TreeNode* root,TreeNode* target,int k){
        if(root==NULL)return;
        inorder(root->left,target,k);
        int d=dis(rr,root)+td-2*dis(rr,lca(rr,target,root));
        if(d==k)ans.push_back(root->val);
        inorder(root->right,target,k);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        rr=root;
        td=dis(root,target);
        inorder(root,target,k);
        return ans;
    }
};