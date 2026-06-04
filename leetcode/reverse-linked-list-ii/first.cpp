class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        ListNode dummy(0);
        dummy.next = head;

        ListNode* before = &dummy;

        // Move before to node just before left
        for (int i = 1; i < left; i++) {
            before = before->next;
        }

        ListNode* curr = before->next;
        ListNode* prev = nullptr;

        // Reverse nodes from left to right
        for (int i = 0; i < right - left + 1; i++) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        // Connect reversed part back
        before->next->next = curr;
        before->next = prev;

        return dummy.next;
    }
};