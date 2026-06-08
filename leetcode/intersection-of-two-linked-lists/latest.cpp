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
    ListNode *getIntersectionNode(ListNode *a, ListNode *b) {
        ListNode* one = a;
        ListNode* two = b;
        while(one != two){
            if(one) one = one->next;
            else one = b;
            if(two) two = two->next;
            else two = a;
        }
        return one;
    }
};