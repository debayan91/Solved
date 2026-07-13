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
    int mx = INT_MIN;
    int dist(TreeNode* root){
        if(!root) return -2000;
        if(!root->left && !root->right){
            mx = max(mx, root->val);
            return root->val;
        }

        int l = dist(root->left);
        int r = dist(root->right);
        int nt = max(l, r);
        int t = l + r + root->val;
        int jr = root->val;

        int d = max({nt + jr, t, jr});

        mx = max(mx, d);

        return max(nt + jr, jr);
    }
    int maxPathSum(TreeNode* root) {
        dist(root);
        return mx;
    }
};