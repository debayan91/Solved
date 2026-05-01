class Solution {
    public int[][] generateMatrix(int n) {
        int[][] res = new int[n][n];
        int count = 1;
        int i = 0;
        int j = 0;
        while (count <= n * n) {
            while (j < n && res[i][j] == 0) {
                res[i][j++] = count++;
            }
            j--;
            i++;
            while (i < n && res[i][j] == 0) {
                res[i++][j] = count++;
            }
            i--;
            j--;
            while (j >= 0 && res[i][j] == 0) {
                res[i][j--] = count++;
            }
            j++;
            i--;
            while (i >= 0 && res[i][j] == 0) {
                res[i--][j] = count++;
            }
            i++;
            j++;
        }
        return res;
    }
}