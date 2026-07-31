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
    int ms = 0;

    array<int, 4> t(TreeNode* root) {
        if (!root) { // null
            return {0, 0, 1, 0};
        }

        if (!root->left && !root->right) { // leaf
            ms = max(ms, root->val);
            return {root->val, root->val, 1, root->val};
        }

        auto [lmx, lmn, lbst, lsum] = t(root->left);
        auto [rmx, rmn, rbst, rsum] = t(root->right);

        if (root->left && root->right) {
            if (root->left->val < root->val && root->right->val > root->val) {
                int l = root->left->val;
                int r = root->right->val;
                int cmn = l, cmx = r;

                bool ok = true;

                if (lbst && lmx < root->val) {
                    l = lsum;
                    cmn = lmn;
                } else {
                    ok = false;
                }

                if (rbst && rmn > root->val) {
                    r = rsum;
                    cmx = rmx;
                } else {
                    ok = false;
                }

                if (ok) {
                    int csum = root->val + l + r;
                    ms = max(ms, csum);
                    return {cmx, cmn, 1, csum};
                }
            }

            return {0, 0, 0, 0};
        }

        if (root->left) {
            if (lbst && lmx < root->val) {
                int csum = root->val + lsum;
                ms = max(ms, csum);
                return {root->val, lmn, 1, csum};
            }
            return {0, 0, 0, 0};
        }

        if (root->right) {
            if (rbst && rmn > root->val) {
                int csum = root->val + rsum;
                ms = max(ms, csum);
                return {rmx, root->val, 1, csum};
            }
            return {0, 0, 0, 0};
        }

        return {0, 0, 0, 0};
    }

    int maxSumBST(TreeNode* root) {
        t(root);
        return ms;
    }
};