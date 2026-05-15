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
    TreeNode* b;
    bool verdict = false;
    void trav(TreeNode* node){
        if(node->left != nullptr) trav(node->left);
        if(node->val == b->val){
            traverse(node, b);
            if(a) verdict = true;
            a = true;
        }
        if(node->right != nullptr) trav(node->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        b = subRoot;
        trav(root);
        return verdict;
    }
};