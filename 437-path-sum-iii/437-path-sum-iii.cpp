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
class Solution{
public:
     long long rootSum(TreeNode* root, long long sum) {
        if (root == nullptr)
            return 0;
        return (long long)(sum == root->val) + (long long)rootSum(root->left, sum - root->val) + (long long)rootSum(root->right, sum - root->val);
    }
    
    int pathSum(TreeNode* root, int sum) {
        if (root == nullptr)
            return 0;
        return rootSum(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
};