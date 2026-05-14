class Solution {
public:
    vector<int> in; 
    void inorder(TreeNode* root) {
        if (root->left != nullptr)
            inorder(root->left);
        in.push_back(root->val);
        if (root->right != nullptr)
            inorder(root->right);
    }
    int kthSmallest(TreeNode* root, int k) { 
        inorder(root); 
        for(int i : in) cout << i << " ";
        return in[k - 1];
    }
};