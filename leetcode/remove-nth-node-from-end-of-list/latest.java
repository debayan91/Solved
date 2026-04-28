/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        if (head == null)
            return null;
        ListNode slow = head;
        ListNode fast = head;

        int i = 1;
        while (i <= n) {
            slow = slow.next;
            i++;
        }

        if (slow == null)
            return head.next;

        while (slow.next != null) {
            slow = slow.next;
            fast = fast.next;
        }

        if (fast.next != null)
            fast.next = fast.next.next;

        return head;
    }
}