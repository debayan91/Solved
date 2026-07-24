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
    int count = 0;
    array<int, 2> t(TreeNode* r){
        if(!r){
            return {0, 0};
        }
        auto [a1, b1] = t(r->left);
        auto [a2, b2] = t(r->right);
        int n = b1 + b2 + 1;
        int sum = a1 + a2 + r->val;
        if(r->val == sum / n) count++;
        return {sum, n};
    }
    int averageOfSubtree(TreeNode* root) {
        t(root);
        return count;
    }
};