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
    public int[][] spiralMatrix(int m, int n, ListNode head) {
        int[][] res = new int[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res[i][j] = -1;
            }
        }
        int count = 0;
        int i = 0;
        int j = 0;
        ListNode temp = head;
        while (count < m * n) {
            while (j < n && res[i][j] == -1) {

                if(temp != null){
                    res[i][j] = temp.val;
                    temp = temp.next;
                }else res[i][j] = -1;

                j++;
                count++;
            }
            j--;
            i++;
            while (i < m && res[i][j] == -1) {
                if(temp != null){
                    res[i][j] = temp.val;
                    temp = temp.next;
                }else res[i][j] = -1;

                i++;
                count++;
            }
            i--;
            j--;
            while (j >= 0 && res[i][j] == -1) {
                if(temp != null){
                    res[i][j] = temp.val;
                    temp = temp.next;
                }else res[i][j] = -1;

                j--;
                count++;
            }
            j++;
            i--;
            while (i >= 0 && res[i][j] == -1) {
                if(temp != null){
                    res[i][j] = temp.val;
                    temp = temp.next;
                }else res[i][j] = -1;

                i--;
                count++;
            }
            i++;
            j++;
        }
        return res;
    }
}