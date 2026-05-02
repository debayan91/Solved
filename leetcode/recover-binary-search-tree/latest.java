/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    TreeNode a = null;
    TreeNode b = null; // a > x and y > b in cases where that should not happen
    TreeNode temp = null;

    public void inorder(TreeNode root) {
        if (root == null)
            return;
        if (root.left != null)
            inorder(root.left);

        if (temp != null) {
            if (a == null && temp.val > root.val) {
                a = temp;
            }
            if (a != null && temp.val > root.val) {
                b = root;
            }
        }
        temp = root;

        if (root.right != null)
            inorder(root.right);
    }

    public void recoverTree(TreeNode root) {
        inorder(root);
        int x = a.val;
        a.val = b.val;
        b.val = x;
    }
}