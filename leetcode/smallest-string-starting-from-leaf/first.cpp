/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    string res = "";
    void t(TreeNode* root, string current) {
        current += 'a' + root->val;
        if(root->left) t(root->left, current);
        if(root->right) t(root->right, current);
        if (!root->left && !root->right) {
            reverse(begin(current), end(current));
            res = min(res, current);
            return;
        }
    }
    string smallestFromLeaf(TreeNode* root) {
        res += (char)('z' + 1);
        t(root, "");
        return res;
    }
};