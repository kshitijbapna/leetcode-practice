/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode *x;
class Codec {
public:
    // TreeNode* x;
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        x=root;
        return "";
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        return x;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));