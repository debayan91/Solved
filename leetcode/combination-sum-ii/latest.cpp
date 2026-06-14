class Solution {
public:
    void backtrack(vector<int>& current, int index, int sum, int target,
              vector<int>& nums, vector<vector<int>>& res) {
        if (sum == target) {
            res.push_back(current);
            return;
        }
        if (index >= size(nums) || sum > target)
            return;
        current.push_back(nums[index]);
        backtrack(current, index + 1, sum + nums[index], target, nums, res);
        current.pop_back();
        while(index + 1 < nums.size() && nums[index] == nums[index + 1]) index++;
        backtrack(current, index + 1, sum, target, nums, res);
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(begin(nums), end(nums));
        vector<int> current;
        backtrack(current, 0, 0, target, nums, res);
        return res;
    }
};