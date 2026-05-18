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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL) return NULL;
        if(head->next == NULL) return head;
        // if(head->next->next == NULL){
        //     head->next->next = head;
        //     head = head->next;
        //     head->next->next = NULL;
        //     return head;
        // }
        ListNode* root = head->next;
        ListNode* temp = head;
        ListNode* prev = NULL;
        while(temp != NULL && temp->next != NULL){
            ListNode* a = temp;
            ListNode* b = temp->next;
            ListNode* c = temp->next->next;
            
            b->next = a;
            a->next = c;
            if(prev != NULL) prev->next = b;

            temp = c;
            prev = a;
        }
        return root;
    }
};