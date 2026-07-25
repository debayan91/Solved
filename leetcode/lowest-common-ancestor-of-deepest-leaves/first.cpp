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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == p) return p;
        if(root == q) return q;
        if(root == NULL) return NULL;

        TreeNode* a = lowestCommonAncestor(root->left, p, q);
        TreeNode* b = lowestCommonAncestor(root->right, p, q);

        if(a && b) return root;

        if(a) return a;
        else if(b) return b;
        else return NULL;
    }
    vector<pair<TreeNode*, int>> v;
    int mx = 0;
    void t(TreeNode* r, int depth){
        if(!r) return;
        t(r->right, depth + 1);
        t(r->left, depth + 1);
        v.push_back({r, depth});
        mx = max(mx, depth);
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        t(root, 1);
        vector<TreeNode*> c;
        for(int i = 0; i < size(v); i++){
            if(v[i].second == mx) c.push_back(v[i].first);
        }
        TreeNode* lca = c[0];
        for(int i = 0; i < size(c); i++){
            lca = lowestCommonAncestor(root, lca, c[i]);
        }
        return lca;
    }
};