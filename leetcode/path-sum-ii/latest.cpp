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
    vector<vector<int>> res;
    void dfs(TreeNode* root, vector<int>& current, int sum, int target){
        if(!root) return;
        current.push_back(root->val);
        sum += root->val;
        if(sum == target && size(current) > 0 && !root->right && !root->left){
            res.push_back(current);
            current.pop_back();
            return;
        }
        dfs(root->left, current, sum, target);
        dfs(root->right, current, sum, target);
        current.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        vector<int> current;
        dfs(root, current, 0, target);
        return res;
    }
};