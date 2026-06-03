class Solution {
public:
    int coinChange(vector<int>& nums, int k) {
        vector<int> dp(k + 1, 0);
        dp[0] = 0;
        sort(begin(nums), end(nums));
        for(int i = 1; i < k + 1; i++){
            dp[i] = INT_MAX;
            for(int c : nums){
                if(i - c < 0) break;
                if(dp[i - c] != INT_MAX) dp[i] = min(dp[i], 1 + dp[i - c]);
            }
        }
        return dp[k] == INT_MAX ? -1 : dp[k];
    }
};