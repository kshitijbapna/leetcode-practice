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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()){
            int sz=q.size(),de=sz;
            double curr=0;
            while(sz--){
                TreeNode* x=q.front();
                q.pop();
                curr+=x->val;
                if(x->left)q.push(x->left);
                if(x->right)q.push(x->right);
            }
            ans.push_back(curr/de);
        }
        return ans;
    }
};