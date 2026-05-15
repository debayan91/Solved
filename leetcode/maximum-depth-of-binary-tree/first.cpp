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
    int max_depth = 0;
    void res(TreeNode* root, int depth){
        if(root == nullptr){
            max_depth = max(max_depth, depth);
            return;
        }
        res(root->right, depth + 1);
        res(root->left, depth + 1);
    }
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        res(root, 0);
        return max_depth;
    }
};