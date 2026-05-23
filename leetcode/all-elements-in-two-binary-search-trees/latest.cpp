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
    void t(vector<int>& res, TreeNode* root){
        if(root == NULL) return;
        t(res, root->left);
        res.push_back(root->val);
        t(res, root->right);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> res;
        t(res, root1);
        t(res, root2);
        sort(res.begin(), res.end());
        return move(res);
    }
};