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
    public ListNode mergeNodes(ListNode head) {
        ListNode temp = head;
        int sum = 0;
        ListNode start = null;
        ListNode end = null;

        while (temp.next != null) {
            if(temp.val == 0){
                start = temp;
                sum = 0;
                temp = temp.next;
                while(temp.val != 0){
                    sum += temp.val;
                    temp = temp.next;
                }
                end = temp;
                start.val = sum;
                if(end.next == null){
                    start.next = null;
                    return head;
                }
                start.next = end;
            }
            temp = end;
        }
        return null;
    }
}