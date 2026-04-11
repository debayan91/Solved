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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if(root == nullptr) return result;
        queue<TreeNode*> q;
        q.push(root);

        while (q.size() > 0) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode* temp = q.front();
                q.pop();
                if (i == n - 1) {
                    result.push_back(temp->val);
                }
                if (temp->left != nullptr)// && visited.count(temp->left) == 0)
                    q.push(temp->left);
                if (temp->right != nullptr)// && visited.count(temp->right) == 0)
                    q.push(temp->right);
            }
        }

        return result;
    }
};