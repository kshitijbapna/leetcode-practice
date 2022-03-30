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
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL)return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<int> ans;
        while(q.empty()==0){
            int x=q.size(),temp=x;
            while(temp--){
                TreeNode* node=q.front();
                q.pop();
                if(node->left)
                q.push(node->left);
                if(node->right)
                q.push(node->right);
                if(temp==0)ans.push_back(node->val);
            }
        }
        return ans;
    }
};