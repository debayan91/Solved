class Solution {
public:
    int count = 0;
    void backtrack(vector<int>& nums, int target, int index, int sum){
        if(index == nums.size() && sum == target){
            count++;
            return;
        }
        if(index == nums.size()) return;
        sum = sum + nums[index];
        backtrack(nums, target, index + 1, sum);
        sum = sum - 2 * nums[index];
        backtrack(nums, target, index + 1, sum);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        backtrack(nums, target, 0, 0);
        return count;
    }
};