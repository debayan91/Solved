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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == headB) return headA;
        vector<ListNode*> a, b;
        ListNode* temp = headA;
        while(temp != NULL) {
            a.push_back(temp);
            temp = temp->next;
        }
        temp = headB;
        while(temp != NULL) {
            b.push_back(temp);
            temp = temp->next;
        }
        int i = size(a) - 1;
        int j = size(b) - 1;
        int count = 0;
        while(i >= 0 && j >= 0){
            if(a[i] == b[j]){
                i--;
                j--;
                count++;
            }else{
                break;
            }
        }
        if(count == 0) return NULL;
        if(i >= 0 && a[i]) return a[i]->next;
        return b[j]->next;
    }
};