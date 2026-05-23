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
        if(head == NULL) return NULL;
        ListNode* temp = head;

        ListNode* node = new ListNode(0);
        ListNode* n = node;

        while(temp != NULL){
            int count = 0;

            int value = temp->val;

            while(temp->next != NULL && temp->next->val == value){
                count++;
                temp = temp->next;
            }

            if(count == 0){
                node->next = temp;
                temp = temp->next;
                node = node->next;
                node->next = NULL;
            }else{
                temp = temp->next;
            }
        }

        return n->next;
    }
};