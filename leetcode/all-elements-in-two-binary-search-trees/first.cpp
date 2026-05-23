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
    vector<int> res;
    void t(TreeNode* root){
        if(root == NULL) return;
        t(root->left);
        res.push_back(root->val);
        t(root->right);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        t(root1);
        t(root2);
        sort(res.begin(), res.end());
        return res;
    }
};