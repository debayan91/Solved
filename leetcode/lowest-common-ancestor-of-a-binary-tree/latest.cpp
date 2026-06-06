/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == p) return p;
        if(root == q) return q;
        if(root == NULL) return NULL;

        TreeNode* a = lowestCommonAncestor(root->left, p, q);
        TreeNode* b = lowestCommonAncestor(root->right, p, q);

        if(a && b) return root;

        if(a) return a;
        else if(b) return b;
        else return NULL;
    }
};