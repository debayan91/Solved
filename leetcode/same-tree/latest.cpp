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
    bool a = true;
    void traverse(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr)
            return;
        if ((!(p == nullptr && q == nullptr) &&
             !(p != nullptr && q != nullptr)) ||
            p->val != q->val) {
            a = false;
            return;
        }
        traverse(p->right, q->right);
        traverse(p->left, q->left);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        traverse(p, q);
        return a;
    }
};