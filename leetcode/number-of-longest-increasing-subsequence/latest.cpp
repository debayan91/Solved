class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = size(nums);
        vector<int> dp(n, 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        int lis = *max_element(begin(dp), end(dp));
        vector<int> counts(n, 0);
        int res = 0;
        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < i; j++){
        //         if(nums[j] < nums[i]){
        //             if(dp[j] + 1 == dp[i]){
        //                 counts[i] += counts[j];
        //             }
        //         }
        //     }
        //     if(dp[i] == lis) res += counts[i];
        // }
        for (int i = 0; i < n; i++) {
            if (dp[i] == 1) {
                counts[i] = 1;
            } else {
                for (int j = 0; j < i; j++) {
                    if (nums[j] < nums[i] && dp[j] + 1 == dp[i]) {
                        counts[i] += counts[j];
                    }
                }
            }
        }
        for (int i = 0; i < n; i++)
            if (dp[i] == lis)
                res += counts[i];
        return res;
    }
};