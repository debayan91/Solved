/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 1;
        while (!q.empty()) {
            int size = q.size();
            vector<TreeNode*> v;
            for (int i = 0; i < size; i++) {
                TreeNode* current = q.front();
                q.pop();
                v.push_back(current->left);
                if (current->left != NULL)
                    q.push(current->left);
                v.push_back(current->right);
                if (current->right != NULL)
                    q.push(current->right);
            }
            int i = 0;
            int j = v.size() - 1;
            if (level % 2 != 0) {
                while (i < j) {
                    if (v[i] == NULL && v[j] == NULL) {

                    } else if (v[i] == NULL) {
                        v[i] = new TreeNode(v[j]->val, v[j]->left, v[j]->right);
                        v[j] = NULL;
                    } else if (v[j] == NULL) {
                        v[j] = new TreeNode(v[i]->val, v[i]->left, v[i]->right);
                        v[i] = NULL;
                    } else {
                        int temp = v[i]->val;
                        v[i]->val = v[j]->val;
                        v[j]->val = temp;
                    }
                    i++;
                    j--;
                }
            }
            level++;
        }
        return root;
    }
};