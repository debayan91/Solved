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
    array<int, 2> dfs(TreeNode* root){
        if(!root) return {INT_MIN, 0};
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        int mx = max({left[0], right[0], root->val});
        int n = left[1] + right[1];
        if(root->val == mx) n++;
        return {mx, n};
    }
    int countDominantNodes(TreeNode* root) {
        auto a = dfs(root);
        return a[1];
    }
};