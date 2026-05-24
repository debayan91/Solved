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
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        stack<pair<TreeNode*, string>> stack;
        stack.push({root, ""});
        while(!stack.empty()){
            TreeNode* temp = stack.top().first;
            if(!temp->right && !temp->left){
                // if leaf node
                stack.top().second += to_string(temp->val);
                sum += stoi(stack.top().second);
            }
            else{
                // if not leaf node
                stack.top().second += to_string(temp->val);
            }
            string s = stack.top().second;
            stack.pop();
            if(temp->left) stack.push({temp->left, s});
            if(temp->right) stack.push({temp->right, s});
        }
        return sum;
    }
};