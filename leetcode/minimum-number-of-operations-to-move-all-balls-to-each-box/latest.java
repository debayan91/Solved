class Solution {
    public int[] minOperations(String boxes) {
        int[] aux = new int[boxes.length()];
        int balls = 0;
        int steps = 0;
        char[] list = boxes.toCharArray();
        for (int i = 0; i < list.length; i++) {
            steps = steps + balls;
            aux[i] = steps;
            if (list[i] == '1') {
                balls++;
            }
        }
        steps = 0;
        balls = 0;
        for (int i = list.length - 1; i >= 0; i--) {
            steps = steps + balls;
            if (list[i] == '1') {
                balls++;
            }
            aux[i] += steps;
        }
        return aux;
    }
}