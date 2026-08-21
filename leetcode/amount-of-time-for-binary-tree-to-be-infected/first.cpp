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
    unordered_map<int, vector<int>> m;
    void t(TreeNode* root) {
        if (root->left) {
            m[root->val].push_back(root->left->val);
            m[root->left->val].push_back(root->val);
            t(root->left);
        }
        if (root->right) {
            m[root->val].push_back(root->right->val);
            m[root->right->val].push_back(root->val);
            t(root->right);
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        t(root);
        int time = 0;
        queue<int> q;
        q.push(start);
        unordered_set<int> vis;
        vis.insert(start);
        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                int current = q.front();
                q.pop();
                for (int a : m[current]) {
                    if (!vis.count(a)) {
                        q.push(a);
                        vis.insert(a);
                    }
                }
            }
            if (!q.empty()) time++;
        }
        return time;
    }
};