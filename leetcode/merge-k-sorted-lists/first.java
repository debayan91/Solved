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
    public ListNode merge(ListNode list1, ListNode list2) {
        // Create a dummy node to act as the start of the merged list
        ListNode dummy = new ListNode(-1);
        ListNode current = dummy;

        // Traverse both lists as long as neither is null
        while (list1 != null && list2 != null) {
            if (list1.val <= list2.val) {
                current.next = list1;
                list1 = list1.next;
            } else {
                current.next = list2;
                list2 = list2.next;
            }
            // Move the current pointer forward
            current = current.next;
        }

        // At least one of the lists is now null. 
        // Attach the remaining elements of the other list.
        if (list1 != null) {
            current.next = list1;
        } else {
            current.next = list2;
        }

        // The merged list starts right after the dummy nod
        return dummy.next;
    }

    public ListNode mergeKLists(ListNode[] lists) {
        if(lists.length == 0) return null;
        ListNode temp = lists[0];
        for (int i = 1; i < lists.length; i++) {
            temp = merge(temp,lists[i]);
        }
        return temp;
    }
}