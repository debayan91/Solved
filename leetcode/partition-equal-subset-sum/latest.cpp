class Solution {
public:
    int b(vector<int>& nums, int index, int sum, int target, vector<vector<int>>& dp){
        if(index == size(nums) || sum > target) return 0;
        if(dp[index][sum] != -1) return dp[index][sum];
        if(sum == target) return 1;
        return dp[index][sum] = max(b(nums, index + 1, sum + nums[index], target, dp),
        b(nums, index + 1, sum, target, dp));
    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(begin(nums), end(nums), 0), n = size(nums);
        if(sum % 2) return 0;
        sum /= 2;
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        return b(nums, 0, 0, sum, dp);
    }
};