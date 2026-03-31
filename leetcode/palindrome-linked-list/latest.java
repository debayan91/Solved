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
    public boolean isPalindrome(ListNode head) {
        if(head == null || head.next == null) return true;
        ListNode fast = head;
        ListNode slow = head;

        while( fast != null && fast.next != null){
            slow = slow.next; //gonna have the midpt
            fast=fast.next.next;
        }   
        ListNode x = null;
        ListNode track = slow;
        while(track!=null){
            ListNode temp = track.next;
            track.next = x;
            x = track;
            track = temp; //track moves forward
        }
        track = x;
        while(track != null){
            if(head.val != track.val) return false;
            head = head.next;
            track = track.next;
        }
        return true;
    }
}