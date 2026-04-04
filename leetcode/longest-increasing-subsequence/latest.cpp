class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = size(nums);
        vector<int> dp(n, 1);
        int m = 1;
        for(int i = 1; i < n; i++){
            int mx = 0;
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i] && dp[j] > mx){
                    mx = dp[j];
                }
                dp[i] = 1 + mx;
                m = max(m, dp[i]);
            }
        }
        return m;
    }
};