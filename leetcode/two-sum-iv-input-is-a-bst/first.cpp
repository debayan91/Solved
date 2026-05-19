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
    unordered_map<int, int> st;
    void t(TreeNode* root){
        if(root == NULL) return;
        t(root->left);
        st[root->val]++;
        t(root->right);
    }
    bool findTarget(TreeNode* root, int k) {
        t(root);
        if(st.size() == 1) return false;
        for(auto& [key, value] : st){
            if(st.count(k - key) != 0){
                if(key == k - key){
                    if(st[key] > 1) return true;
                    else continue;
                }
                else return true;            
            }
        }
        return false;
    }
};
