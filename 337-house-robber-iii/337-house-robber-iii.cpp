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
    static int max(int a, int b) {
        return a > b ? a : b;
    }

    static void maxMoney(struct TreeNode* root, int *withMe, int *withoutMe) {
        int wMeL, woMeL; // max money robbed: (with/without me for left child)
        int wMeR, woMeR; // max money robbed: (with/without me for right child)

        if (!root)
            return;
        wMeL = woMeL = wMeR = woMeR = 0;
        maxMoney(root->left, &wMeL, &woMeL);
        maxMoney(root->right, &wMeR, &woMeR);
        *withMe = woMeL + woMeR + root->val;
        *withoutMe = max(wMeL, woMeL) + max(wMeR, woMeR);
    }

    int rob(struct TreeNode* root) {
        int withMe, withoutMe;

        withMe = withoutMe = 0;
        maxMoney(root, &withMe, &withoutMe);
        return max(withMe, withoutMe);
    }
};