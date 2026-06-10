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
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head)
            return head;
        ListNode* n = new ListNode(0);
        ListNode* r = n;
        ListNode* temp = head;
        while (temp != NULL) {
            // push to n

            int value = temp->val;

            n->next = temp;
            temp = temp->next;
            n = n->next;
            n->next = NULL;
            // go to next non duplicate element

            while(temp && temp->val == value) temp = temp->next;


        }
        return r->next;
    }
};