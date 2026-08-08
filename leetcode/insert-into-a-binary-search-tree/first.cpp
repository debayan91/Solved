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
    void t(TreeNode* root, int val) {
        if (!root->left && val < root->val) {
            root->left = new TreeNode(val);
            return;
        } else if (!root->right && val > root->val) {
            root->right = new TreeNode(val);
            return;
        } else if (val < root->val) {
            t(root->left, val);
        } else {
            t(root->right, val);
        }
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) {
            root = new TreeNode(val);
            return root;
        }
        t(root, val);
        return root;
    }
};