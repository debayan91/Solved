class Solution {
    public int[] findDegrees(int[][] matrix) {
        int[] a = new int[matrix.length];
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[i].length; j++) {
                a[i] += matrix[i][j];
            }
        }
        return a;
    }
}