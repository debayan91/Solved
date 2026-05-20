class Solution {
public:
    vector<vector<int>> res;
    int n;
    int k;
    void backtrack(vector<int>& current, int index){
        if(current.size() == k){
            res.push_back(current);
            return;
        }
        if(index > n) return;
        current.push_back(index);
        backtrack(current, index + 1);
        current.pop_back();
        backtrack(current, index + 1);
    }
    vector<vector<int>> combine(int n, int k) {
        this->k = k;
        this->n = n;
        vector<int> current;
        backtrack(current, 1);
        return res;
    }
};