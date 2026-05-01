class Solution {
    public int[][] spiralMatrixIII(int rows, int cols, int rStart, int cStart) {

        int range = 1;
        int count = 0;

        int[][] res = new int[rows*cols][2];
        int i = rStart;
        int j = cStart;


        res[count] = new int[]{i, j};
        count++;


        while (count < rows * cols) {
            // if (i < rows && j < cols && j > -1 && i > -1 && count < rows*cols) {
            //     res[count] = new int[]{i, j};
            //     count++;
            // }
            //right down
            for (int x = 0; x < range; x++) {
                j++;
                if (i < rows && j < cols && j > -1 && i > -1 && count < rows*cols) {
                    res[count] = new int[]{i, j};
                    count++;
                }
            }
            for (int x = 0; x < range; x++) {
                i++;
                if (i < rows && j < cols && j > -1 && i > -1 && count < rows*cols) {
                    res[count] = new int[]{i, j};
                    count++;
                }
            }

            range++;

            //left up

            for (int x = 0; x < range; x++) {
                j--;
                if (i < rows && j < cols && j > -1 && i > -1 && count < rows*cols) {
                    res[count] = new int[]{i, j};
                    count++;
                }
            }
            for (int x = 0; x < range; x++) {
                i--;
                if (i < rows && j < cols && j > -1 && i > -1 && count < rows*cols) {
                    res[count] = new int[]{i, j};
                    count++;
                }
            }
            range++;            
        }
        return res;
    }
}