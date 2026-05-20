class Solution {
public:
    void backtrack(vector<int>& current, int index, int n, int k, vector<vector<int>>& res){
        if(current.size() == k){
            res.push_back(current);
            return;
        }
        if(index > n) return;
        current.push_back(index);
        backtrack(current, index + 1, n, k, res);
        current.pop_back();
        backtrack(current, index + 1, n, k, res);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> current;
        backtrack(current, 1, n, k, res);
        return move(res);
    }
};