class Solution {
public:
    vector<vector<int>> res;
    vector<int> nums;
    int target;
    void backtrack(int index, vector<int>& current, int sum){
        if(sum == target){
            res.push_back(current);
            return;
        }
        if(sum > target || index == nums.size()){
            return;
        }

        current.push_back(nums[index]);
        sum += nums[index];
        backtrack(index, current, sum);

        current.pop_back();
        sum -= nums[index];
        backtrack(index + 1, current, sum);

        // current.push_back(nums[index]);
        // sum += nums[index];
        // backtrack(index, current, sum);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        this->nums = nums;
        this->target = target;
        vector<int> current;
        backtrack(0, current, 0);
        return res;
    }
};