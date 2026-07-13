class Solution {
public:
    unordered_map<int, int> pos;
    TreeNode* build(int il, int ir, int pl, int pr, vector<int>& preorder, vector<int>& inorder){
        if(il > ir) return NULL;
        int rv = preorder[pl];
        int index = pos[rv];
        int lsize = index - il;
        TreeNode* root = new TreeNode(rv);
        root->left = build(il, index - 1, pl + 1, pl + lsize, preorder, inorder);
        root->right = build(index + 1, ir, pl + lsize + 1, pr, preorder, inorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = size(inorder);
        for(int i = 0; i < n; i++){
            pos[inorder[i]] = i;
        }
        return build(0, n - 1, 0, n - 1, preorder, inorder);
    }
};