class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = size(cost);
        if(n == 2) return min(cost[0], cost[1]);
        int cr_1 = 0;
        int cr_2 = 0;
        for(int i = 2; i < n + 1; i++){
            int cr = min(cr_1 + cost[i - 1], cr_2 + cost[i - 2]);
            cr_2 = cr_1;
            cr_1 = cr;
        }
        return cr_1;
    }
};