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
    public void reorderList(ListNode head) {
        if(head == null || head.next == null) return;
        int n = 1;
        ListNode tail = head;
        while(tail.next != null){
            n++;
            tail = tail.next;
        }//n = length
        // so the number of nodes that are gonna stay in order are n/2 if even or n/2 +1 if odd
        int start = (n+1)/2;
        ListNode temp = head;
        int i = 0;
        while(i < start - 1){
            temp = temp.next;
            i++;
        }
        //temp is the end of the same - order ll;
        ListNode new_head = temp.next;
        temp.next = null;

        //now reverse the new list;

        temp = new_head;
        ListNode tracker = new_head;
        ListNode prev_node = null;

        while(temp != null){

            tracker = temp.next;

            temp.next = prev_node;
            prev_node = temp;

            temp = tracker;

        }

        temp = head;
        ListNode temp1 = prev_node;

        ListNode head_new = new ListNode(0);
        ListNode t = head_new;
        while(temp != null && temp1 != null){
            ListNode holder = temp.next;
            ListNode holder2 = temp1.next;
            t.next = temp;
            t = t.next;

            t.next = temp1;
            t = t.next;

            temp = holder;
            temp1 = holder2;
        }
        if(temp != null) t.next = temp;
        else t.next = temp1;
    }
}