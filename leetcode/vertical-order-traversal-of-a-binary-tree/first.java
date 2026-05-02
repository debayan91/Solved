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

    //pair class for row + col
    class Pair {
        TreeNode node;
        int row, col;

        Pair(TreeNode n, int r, int c) {
            node = n;
            row = r;
            col = c;
        }
    }

    public List<List<Integer>> verticalTraversal(TreeNode root) {
        List<List<Integer>> res = new ArrayList<>();
        TreeMap<Integer, TreeMap<Integer, PriorityQueue<Integer>>> map = new TreeMap<>();

        //bfs - auto sorting by row

        Queue<Pair> q = new ArrayDeque<>();

        q.add(new Pair(root, 0, 0));

        while (!q.isEmpty()) {
            Pair p = q.poll();
            TreeNode node = p.node;
            int r = p.row;
            int c = p.col;

            map.computeIfAbsent(c, k -> new TreeMap<>()).computeIfAbsent(r, k -> new PriorityQueue<>()).add(node.val);

            if (node.left != null)
                q.add(new Pair(node.left, r + 1, c - 1));

            if (node.right != null)
                q.add(new Pair(node.right, r + 1, c + 1));
        }

        for (var col : map.values()) {
            List<Integer> list = new ArrayList<>();
            for (var pq : col.values()) {
                while (!pq.isEmpty()) {
                    list.add(pq.poll());
                }
            }
            res.add(list);
        }

        return res;

    }
}