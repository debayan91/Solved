class Solution {
public:
    int value; 
    int counter = 0;
    int limit;
    int answer = -1;
    void inorder(TreeNode* root) {
        if(root == nullptr || answer != -1) return;
        if (root->left != nullptr) inorder(root->left);

            value = root->val;
            //cout << "value is " << value << " counter is " << counter << endl;
            counter++;
            if(counter == limit){
                answer = value;
                return;
            }

        if (root->right != nullptr) inorder(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        limit = k; 
        inorder(root); 
        return answer;
    }
};