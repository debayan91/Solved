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
    int maxlen = 0;
    int diameter(TreeNode* root){
        if(!root) return 0;
        int left = diameter(root->left) + 1;
        int right = diameter(root->right) + 1;
        maxlen = max(maxlen, left + right);
        return max(left, right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        diameter(root);
        return maxlen - 2;
    }
};