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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> m;
        for(auto& d : descriptions){
            if(m.count(d[0]) == 0){
                m[d[0]] = new TreeNode(d[0]);
            }
            if(m.count(d[1]) == 0){
                m[d[1]] = new TreeNode(d[1]);
            }
        }
        for(auto& d : descriptions){
            if(d[2]){
                m[d[0]]->left = m[d[1]];
            }else{
                m[d[0]]->right = m[d[1]];
            }
        }
        for(auto& d : descriptions){
            m[d[1]] = NULL;
        }
        for(auto& d : descriptions){
            if(m[d[0]] != NULL) return m[d[0]];
        }
        return NULL;
    }
};