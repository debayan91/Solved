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
    ListNode* partition(ListNode* head, int x) {
        if (head == NULL)
            return NULL;

        // the big list
        ListNode* h = new ListNode(0);
        ListNode* c = h;

        ListNode* temp = head;

        ListNode* prev = NULL;

        while (temp != NULL) {
            if (temp->val >= x) {
                if (prev) {

                    prev->next = temp->next;
                    h->next = temp;
                    h = h->next;
                    h->next = NULL;
                    temp = prev->next;

                } else {

                    ListNode* nxt = temp->next;
                    h->next = temp;
                    h = h->next;
                    h->next = NULL;
                    temp = nxt;
                    head = temp;
                    
                }
            } else {
                prev = temp;
                temp = temp->next;
            }
        }

        temp = head;
        if (head) {
            while (temp->next != NULL)
                temp = temp->next;
        } else
            return c->next;
        temp->next = c->next;
        return head;
    }
};