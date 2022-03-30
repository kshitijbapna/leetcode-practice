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
    void find(TreeNode *root,int sum,vector<int>& path,vector<vector<int>> &paths){
        if(root==NULL)return;
        path.push_back(root->val);
        sum-=root->val;
        if(root->left==NULL&&root->right==NULL&&sum==0)
            paths.push_back(path);
        find(root->right,sum,path,paths);
        find(root->left,sum,path,paths);
                path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> paths;
        vector<int> path;
        find(root,sum,path,paths);
        return paths;
    }
};