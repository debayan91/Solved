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
    vector<TreeNode*> order;
    void pre(TreeNode* root){
        if(!root) return;
        order.push_back(root);
        pre(root->left);
        pre(root->right);
    }
    void flatten(TreeNode* root) {
        if(root == NULL) return;
        pre(root);
        TreeNode* temp = root;
        temp->left = NULL;
        for(int i = 1; i < size(order); i++){
            temp->right = order[i];
            temp->left = NULL;
            temp = temp->right;
        }
    }
};