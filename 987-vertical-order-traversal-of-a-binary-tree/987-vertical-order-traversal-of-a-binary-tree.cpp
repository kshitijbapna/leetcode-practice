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
    map<int,vector<pair<int,int>>> m;
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        int level=0;
        while(q.size()){
            int sz=q.size();
            while(sz--){
                pair<TreeNode*,int> p=q.front();
                q.pop();
                m[p.second].push_back({level,p.first->val});
                if(p.first->left)q.push({p.first->left,p.second-1});
                if(p.first->right)q.push({p.first->right,p.second+1});
            }
            level++;
        }
        vector<vector<int>> ans;
        for(auto &x : m){
            sort(x.second.begin(),x.second.end());
            vector<int> curr;
            for(auto y : x.second){
                curr.push_back(y.second);
            }
            ans.push_back(curr);
        }
        return ans;
    }
};