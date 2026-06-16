class Solution {
public:
    vector<vector<int>> res;
    void backtrack(vector<int>& current, int index, int sum, int target, int k, vector<int>& nums) {
        if(sum == target && size(current) == k){
            res.push_back(current);
            return;
        }
        if(index < 0 || current.size() > k) return;
        while(index >= 0 && nums[index] > target) index--;
        current.push_back(nums[index]);
        backtrack(current, index - 1, sum + nums[index], target, k, nums);
        current.pop_back();
        backtrack(current, index - 1, sum, target, k, nums);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<int> current;
        backtrack(current, 8, 0, n, k, nums);
        return res;
    }
};