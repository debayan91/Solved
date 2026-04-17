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
    public ListNode merge_sort(ListNode head){
        if(head == null || head.next == null){
            return head;
        }

        //we are gonna split the list
        ListNode slow = head;
        ListNode fast = head.next;
        while(fast != null && fast.next != null){
            slow = slow.next;
            fast = fast.next.next;
        }
        ListNode head1 = head;
        ListNode head2 = slow.next;
        slow.next = null;
        //ll divided into halves starting at head1 and head2
        
        return merge(merge_sort(head1),merge_sort(head2));
    }

    public ListNode merge(ListNode head1, ListNode head2) {
        ListNode n = new ListNode(0);
        ListNode k = n;
        while (head1 != null && head2 != null) {
            if (head1.val < head2.val) {
                n.next = head1;
                head1 = head1.next;
            } else {
                n.next = head2;
                head2 = head2.next;
            }
            n = n.next;
        }
        if(head1 != null) {
            n.next = head1;
        }
        if(head2 != null) {
            n.next = head2;
        }
        return k.next;
    }

    public ListNode sortList(ListNode head) {
        return merge_sort(head);
    }
}