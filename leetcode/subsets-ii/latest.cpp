class Solution {
public:
    vector<vector<int>> res;
    void backtrack(vector<int>& current, vector<int>& nums, int index) {
        if (index == nums.size()) {
            res.push_back(current);
            return;
        }
        current.push_back(nums[index]);
        backtrack(current, nums, index + 1);
        index++;
        while(index < nums.size() && nums[index] == nums[index - 1]) index++;
        current.pop_back();
        backtrack(current, nums, index);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> current;
        backtrack(current, nums, 0);
        return res;
    }
};