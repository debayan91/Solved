/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head) return head;

        unordered_set<ListNode*> nodes;

        while(head){
            if(nodes.count(head)) return head;
            else nodes.insert(head);
            head = head->next;
        }

        return NULL;
    }
};