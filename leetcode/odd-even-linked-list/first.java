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
    public ListNode oddEvenList(ListNode head) {
        ListNode end = head;
        if (head == null || head.next == null || head.next.next == null) return head;
        int i = 0;
        while(end.next!=null){ end = end.next; i++; } //end reaches the emd

        ListNode start = end;
        ListNode temp = head;


        ListNode even = null;
        ListNode odd = null;
        ListNode next_odd = null;

        int count = (i+1)/2;

        while(count > 0 && temp != null && temp.next != null){

            odd = temp;
            even = temp.next;
            odd.next = even.next;

            start.next = even;
            start = even;
            even.next = null;

            temp = odd.next;

            count--;
        }

        return head;
    }
}