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
    public ListNode rotateRight(ListNode head, int k) {
        if(head == null || head.next == null || k == 0) return head;
        int n = 1; //length
        ListNode tail = head;
        while(tail.next != null){
            n++;
            tail = tail.next;
        }
        // tail is the last element
        ListNode temp = head;
        k = k%n;
        if(k == 0) return head;
        int start = n - k; 
        int i = 0;
        while(i < start-1){ temp = temp.next; i++; }
        //temp is now the real tail

        ListNode new_head = temp.next;
        temp.next = null;

        tail.next = head;

        return new_head;

    }
}