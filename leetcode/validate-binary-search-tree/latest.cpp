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
    bool isbst(TreeNode* root, long long min, long long max){
        if(root == nullptr) return true;
        if(root->val >= max || root->val <= min) return false;
        long long currentval = root->val;
        bool flag = false;
            return(isbst(root->left,min,currentval)&&isbst(root->right,currentval,max));

    }
    bool isValidBST(TreeNode* root) {
        return isbst(root,LLONG_MIN,LLONG_MAX);
    }
};