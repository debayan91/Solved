class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(begin(costs), end(costs));
        int count = 0;
        int i = 0;
        while (i < size(costs)) {
            coins -= costs[i];
            if (coins < 0)
                break;
            count++;
            i++;
        }
        return count;
    }
};