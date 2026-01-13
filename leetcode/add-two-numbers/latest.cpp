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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* new1 = new ListNode(0);
        ListNode* r = new1;
        int carry = 0;
        int sum;
        while(l1 != nullptr || l2 != nullptr || carry){
            sum = 0;
            if(carry){
                sum += carry;
            }
            if( l1 && l2){
                sum += l1->val + l2->val;
                l1 = l1->next;
                l2 = l2->next;
            }else if(l1){
                sum += l1->val;
                l1 = l1->next;
            }else if(l2){
                sum += l2->val;
                l2 = l2->next;
            }

            if(sum > 9){
                carry = sum/10;
                sum = sum % 10;
            }else{
                carry = 0;
            }

            //if(sum || carry) 
            new1->next = new ListNode(sum);
            new1 = new1->next;
        }
        return r->next;
    }
};