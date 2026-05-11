class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        res.push_back({1});
        for(int i = 2; i < numRows + 1; i++){
            vector<int> row(i);
            row[0] = row[i - 1] = 1;
            for(int j = 1; j < i - 1; j++){
                row[j] = res[i - 2][j] + res[i - 2][j - 1];
            }
            res.push_back(row);
        }
        return res;
    }
};