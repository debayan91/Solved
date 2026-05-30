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
    bool res(TreeNode* a, TreeNode* b){
        if(a == NULL && b == NULL) return true;
        if(a && !b || b && !a) return false;
        if(a->val == b->val) return (res(a->left, b->right) && res(a->right, b->left));
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        return res(root->left, root->right);
    }
};