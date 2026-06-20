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
    void makeleft(TreeNode* root, int l, int h, vector<int>& nums){
        if(!root || l < 0 || h > nums.size() - 1 || l > h) return;
        int n = nums.size();
        int index = l;
        int mx = nums[l];
        for(int i = l; i < h + 1; i++){
            if(nums[i] > mx){
                mx = nums[i];
                index = i;
            }
        }
        root->left = new TreeNode(mx);
        root = root->left;
        makeleft(root, l, index - 1, nums);
        makeright(root, index + 1, h, nums);
    }
    void makeright(TreeNode* root, int l, int h, vector<int>& nums){
        if(!root || l < 0 || h > nums.size() - 1 || l > h) return;
        int n = nums.size();
        int index = l;
        int mx = nums[l];
        for(int i = l; i < h + 1; i++){
            if(nums[i] > mx){
                mx = nums[i];
                index = i;
            }
        }
        root->right = new TreeNode(mx);
        root = root->right;
        makeleft(root, l, index - 1, nums);
        makeright(root, index + 1, h, nums);
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n = nums.size();
        int index = 0;
        int mx = nums[0];
        for(int i = 1; i < n; i++){
            if(nums[i] > mx){
                mx = nums[i];
                index = i;
            }
        }
        TreeNode* root = new TreeNode(mx);
        makeleft(root, 0, index - 1, nums);
        makeright(root, index + 1, n - 1, nums);
        return root;
    }
};