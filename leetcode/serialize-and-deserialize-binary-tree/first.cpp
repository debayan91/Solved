/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        if (root == NULL)
            return "";
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();

            if (current)
                out << current->val;
            else
                out << "null";

            out << ",";

            if (current) {
                q.push(current->left);
                q.push(current->right);
            }
        }

        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "")
            return NULL;

        queue<TreeNode*> q;

        stringstream ss(data);
        string token;
        getline(ss, token, ',');

        TreeNode* root = new TreeNode(stoi(token));
        q.push(root);

        while(!q.empty()){
            TreeNode* current = q.front();
            q.pop();
            
            getline(ss, token, ',');
            string left = token;
            getline(ss, token, ',');
            string right = token;

            if(left != "null"){
                TreeNode* l = new TreeNode(stoi(left));
                current->left = l;
                q.push(l);
            }
            if(right != "null"){
                TreeNode* r = new TreeNode(stoi(right));
                current->right = r;
                q.push(r);
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));