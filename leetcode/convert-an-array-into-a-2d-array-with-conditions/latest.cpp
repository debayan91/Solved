class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> m;
        for (int i : nums) m[i]++;
        vector<vector<int>> res;
        while (true) {
            vector<int> temp;
            for (auto& [a, b] : m) {
                if (b > 0) {
                    temp.push_back(a);
                    b--;
                }
            }
            if(temp.size() == 0) break;
            res.push_back(temp);
        }
        return res;
    }
};