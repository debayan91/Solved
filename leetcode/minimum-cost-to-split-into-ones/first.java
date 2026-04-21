class Solution {
    public int minCost(int n) {
        long cost = 0;
        while (n != 1) {
            cost += n - 1;
            n--;
        }
        return (int)cost;
    }
}