class Solution {
    public int maxCoins(int[] piles) {
        int n = piles.length;
        int chances = n / 3;
        Arrays.sort(piles);
        int sum = 0;
        int index = n - 1;
        index--; //Alice takes
        for (int i = 0; i < chances; i++) {
            sum += piles[index];
            index--;
            index--;
        }
        return sum;
    }
}