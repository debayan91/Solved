class Solution {
    public int[] findDegrees(int[][] matrix) {
        int[] a = new int[matrix.length];
        for(int i = 0 ;i<matrix.length;i++){
            a[i] = Arrays.stream(matrix[i]).sum();
        }
        return a;
    }
}