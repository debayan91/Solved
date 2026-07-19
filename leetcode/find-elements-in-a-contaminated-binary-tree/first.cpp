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
class FindElements {
public:
    unordered_set<int> st;
    void fill(TreeNode* root){
        if(!root) return;
        st.insert(root->val);
        if(root->left) root->left->val = root->val * 2 + 1;
        if(root->right) root->right->val = root->val * 2 + 2;
        fill(root->left);
        fill(root->right);
    }
    FindElements(TreeNode* root) {
        root->val = 0;
        fill(root);
    }
    
    bool find(int target) {
        return st.count(target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */