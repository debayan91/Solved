class Solution {
public:
    long long maxEarnings(vector<vector<int>>& m) {
        sort(begin(m), end(m));
        int n = size(m);

        vector<int> ends(n); 
        int k = 0;
        for(int& i : ends) i = k++;
        sort(begin(ends), end(ends), [&](auto& a, int b){
           return m[a][1] < m[b][1]; 
        });

        vector<long long> dp(n, 0);

        long long best = LLONG_MIN, p = 0;

        for(int i = 0; i < n; i++){
            int start = m[i][0];
            while(p < n && m[ends[p]][1] <= start){
                best = max(best, dp[ends[p]] - m[ends[p]][1]); p++;
            }
            dp[i] = m[i][2];
            if(best != LLONG_MIN) dp[i] = max(dp[i], m[i][2] + start + best);
        }
        return *max_element(begin(dp), end(dp));
    }
};