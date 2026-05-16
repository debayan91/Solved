class Solution {
public:
    int min_depth = INT_MAX;
    void res(TreeNode* root, int depth){
        if(root->right == NULL && root->left == NULL){
            min_depth = min(min_depth, depth);
            return;
        }
        if(root->right != nullptr) res(root->right, depth + 1);
        if(root->left != NULL) res(root->left, depth + 1);
    }
    int minDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        res(root, 0);
        return min_depth + 1;
    }
};