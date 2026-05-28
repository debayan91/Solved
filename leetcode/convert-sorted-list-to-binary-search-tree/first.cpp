/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* build(vector<int>& nums, int l, int h, TreeNode* root){
        if(l > h) return NULL;
        int mid = (l + h) / 2;
        TreeNode* current = new TreeNode(nums[mid]);
        current->left = build(nums, l, mid -1, current);
        current->right = build(nums, mid + 1, h, current);
        return current;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL) return NULL;
        vector<int> nums;
        while(head != NULL){
            nums.push_back(head->val);
            head = head->next;
        }
        int n = nums.size();
        int mid = n / 2;

        TreeNode* root = new TreeNode(nums[mid]);
        root->left = build(nums, 0, mid - 1, root);
        root->right = build(nums, mid + 1, n - 1, root);
        return root;
    }
};