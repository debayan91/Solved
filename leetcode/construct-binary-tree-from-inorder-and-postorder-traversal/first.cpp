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
    TreeNode* build(int l1, int r1, int l2, int r2, unordered_map<int, int>& pos, vector<int>& inorder, vector<int>& postorder){
        if(l1 > r1) return NULL;
        int rv = postorder[r2];
        TreeNode* root = new TreeNode(rv);

        int index = pos[rv];
        int lsize = index - l1;

        root->left = build(l1, index - 1, l2, l2 + lsize - 1, pos, inorder, postorder);
        root->right = build(index + 1, r1, l2 + lsize, r2 - 1, pos, inorder, postorder);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> pos;
        for(int i = 0; i < inorder.size(); i++){
            pos[inorder[i]] = i;
        }
        return build(0, size(inorder) - 1, 0, size(postorder) - 1, pos, inorder, postorder);
    }
};