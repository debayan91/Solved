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
    TreeNode* lowestCommonAncesto(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == p) return p;
        if(root == q) return q;
        if(root == NULL) return NULL;

        TreeNode* a = lowestCommonAncesto(root->left, p, q);
        TreeNode* b = lowestCommonAncesto(root->right, p, q);

        if(a && b) return root;

        if(a) return a;
        else if(b) return b;
        else return NULL;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(root->left && root->val > p->val && root->val > q->val) root = root->left;
        while(root->right && root->val < p->val && root->val < q->val) root = root->right;
        return lowestCommonAncesto(root, p, q);
    }
};