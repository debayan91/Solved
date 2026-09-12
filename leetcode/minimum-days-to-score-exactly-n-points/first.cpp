class Solution {
public:
    int minDays(int n) {
        vector<long long> dp(n + 1, INT_MAX);
        int k = 1; dp[0] = 0;
        while(1){
            ////

            int x = k * (k + 1) / 2; if(x > n) break;

            int time = k + 1;

            for(int i = x; i < n + 1; i++){
                dp[i] = min(dp[i], dp[i - x] + time);
            }

            
            
            
            ////
            k++;
        }
        return dp.back() - 1;
    }
};