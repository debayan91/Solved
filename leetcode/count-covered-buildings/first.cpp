class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& b) {
        vector<array<int, 2>> r(n + 1, {INT_MAX, -1}), c(n + 1, {INT_MAX, -1});
        for(auto& a : b){
            int i = a[0], j = a[1];
            r[i][0] = min(r[i][0], j);
            r[i][1] = max(r[i][1], j);
            c[j][0] = min(c[j][0], i);
            c[j][1] = max(c[j][1], i);
        } int count = 0;
        for(auto& a : b){
            int i = a[0], j = a[1];
            if(j > r[i][0] && j < r[i][1] && i > c[j][0] && i < c[j][1]) count++;
        }
        return count;
    }
};