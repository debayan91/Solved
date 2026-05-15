class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == nullptr) return res;
        queue<TreeNode*> q;
        q.push(root);
        int index = 0;
        while (!q.empty()) {
            int size = q.size();
            vector<int> v;
            for (int i = 0; i < size; i++) {
                TreeNode* c = q.front();
                q.pop();
                v.push_back(c->val);
                if (c->left != NULL)
                    q.push(c->left);
                if (c->right != NULL)
                    q.push(c->right);
            }
            if(index % 2 != 0) reverse(v.begin(), v.end());
            index++;
            res.push_back(move(v));
        }
        return res;
    }
};