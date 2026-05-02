class Solution {
    public int climbStairs(int n) {
        int[] a = new int[2];

        a[0] = 1;
        a[1] = 2;

        if (n < 3)
            return n;

        for (int i = 3; i < n + 1; i += 2) {
            int x = a[0] + a[1];
            int y = x + a[1];
            a[0] = x;
            a[1] = y;
        }

        if (n % 2 != 0)
            return a[0];
        return a[1];
    }
}