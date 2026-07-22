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
    ListNode* mergeInBetween(ListNode* head, int A, int B, ListNode* h2) {
        ListNode* a, *b;
        int i = 0;
        ListNode* temp = head;
        while(temp != NULL){
            i++;
            if(i == A) a = temp;
            if(i == B + 2) b = temp;
            temp = temp->next;
        }
        a->next = h2;
        while(h2->next != NULL) h2 = h2->next;
        h2->next = b;
        return head;
    }
};