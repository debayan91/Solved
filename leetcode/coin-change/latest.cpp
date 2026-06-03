class Solution {
public:
    int coinChange(vector<int>& nums, int k) {
        vector<int> dp(k + 1, INT_MAX);
        dp[0] = 0;
        sort(begin(nums), end(nums));
        for (int i = 1; i <= k; i++) {
            for (int j = 0; j < nums.size() && nums[j] <= i; j++) {
                if (dp[i - nums[j]] != INT_MAX) {
                    dp[i] = min(dp[i], 1 + dp[i - nums[j]]);
                }
            }
        }
        return dp[k] == INT_MAX ? -1 : dp[k];
    }
};