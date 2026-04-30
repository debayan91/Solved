class Solution {
    public int maxIncreaseKeepingSkyline(int[][] grid) {
        int n = grid.length;
        int[] x = new int[n];
        int[] y = new int[n];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if(grid[i][j]>x[i]) x[i] = grid[i][j];
                if(grid[j][i]>y[i]) y[i] = grid[j][i];
            }
        }
        int sum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int max = Math.min(x[i],y[j]);
                sum += max - grid[i][j];
            }
        }
        return sum;
    }
}