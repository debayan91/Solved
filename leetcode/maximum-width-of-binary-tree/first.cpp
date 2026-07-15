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
    int widthOfBinaryTree(TreeNode* root) {
        __int128 mx = 0;

        queue<pair<TreeNode*, __int128>> q;
        q.push({root, 1});

        while (!q.empty()) {
            int sz = q.size();

            __int128 offset = q.front().second;

            __int128 mn = LLONG_MAX;
            __int128 mxPos = LLONG_MIN;

            for (int i = 0; i < sz; i++) {
                auto [node, pos] = q.front();
                q.pop();

                pos -= offset;

                mn = min(mn, pos);
                mxPos = max(mxPos, pos);

                if (node->left)
                    q.push({node->left, 2 * pos});

                if (node->right)
                    q.push({node->right, 2 * pos + 1});
            }

            mx = max(mx, mxPos - mn + 1);
        }

        return mx;
    }
};