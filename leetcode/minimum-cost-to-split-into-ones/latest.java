class Solution {
    public int minCost(int n) {
        int cost = 0;
        while (n != 1) {
            cost += n - 1;
            n--;
        }
        return cost;
    }
}