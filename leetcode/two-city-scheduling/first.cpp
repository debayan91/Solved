class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = size(costs);
        sort(begin(costs), end(costs), [](auto& a, auto& b){
            return a[0] - a[1] < b[0] - b[1];
        });
        int cost = 0;
        for(int i = 0; i < n; i++){
            cost += i < n / 2 ? costs[i][0] : costs[i][1];
        }
        return cost;
    }
};