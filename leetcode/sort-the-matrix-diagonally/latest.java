class Solution {
    public int[][] diagonalSort(int[][] mat) {
        List<Integer> list = new ArrayList<>();
        int columns = mat[0].length;
        int rows = mat.length;

        for (int i = 0; i < columns; i++) {

            //starts
            int x = 0;
            int y = i;

            while (x < rows && y < columns) {
                list.add(mat[x][y]);
                x++;
                y++;
            }

            Collections.sort(list);

            x = 0;
            y = i;

            int index = 0;
            while (x < rows && y < columns) {
                mat[x][y] = list.get(index);
                index++;
                x++;
                y++;
            }

            list.clear();

        }

        for (int i = 1; i < rows; i++) {

            //starts
            int x = i;
            int y = 0;

            while (x < rows && y < columns) {
                list.add(mat[x][y]);
                x++;
                y++;
            }

            Collections.sort(list);

            x = i;
            y = 0;

            int index = 0;
            while (x < rows && y < columns) {
                mat[x][y] = list.get(index);
                index++;
                x++;
                y++;
            }

            list.clear();

        }

        return mat;
    }
}