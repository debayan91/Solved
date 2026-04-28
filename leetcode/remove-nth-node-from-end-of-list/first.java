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
        ListNode a = head;
        ListNode h = new ListNode(-255);
        h.next = head;
        int count = 0;
        while (a.next != null) {
            a = a.next;
            count++;
        }
        a = h;
        for(int i = 0;i<=count-n;i++){
            a = a.next;
        }
        if(a.next.next == null) a.next = null;
        else{
            a.next = a.next.next;
        }
        System.out.println(a.val);
        return h.next;
    }
}