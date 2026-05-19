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
    //unordered_map<int, int> st;
    vector<int> nums;
    void t(TreeNode* root){
        if(root == NULL) return;
        t(root->left);
        nums.push_back(root->val);
        t(root->right);
    }
    bool findTarget(TreeNode* root, int target) {
        t(root);
        if(nums.size() == 1) return false;
        // for(auto& [key, value] : st){
        //     if(st.count(k - key) != 0){
        //         if(key == k - key){
        //             if(st[key] > 1) return true;
        //             else continue;
        //         }
        //         else return true;            
        //     }
        // }
        int i = 0;
        int j = nums.size() - 1;
        while(i < j){
            if(nums[i] + nums[j] == target){
                return true;
            }
            else if(nums[i] + nums[j] < target) i++;
            else j--;
        }
        return false;
    }
};
