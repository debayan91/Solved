class Solution {
public:
    long long f(string &s, string &t, vector<vector<string>>& rules, vector<int>& costs,
          int index, vector<long long>& dp) {
        
        int n = size(s);
        if (index == n)
            return 0; // end
        // if already done
        if (dp[index] >= 0)
            return dp[index];
        long long res = LLONG_MAX;
        // if already ok
        if (s[index] == t[index]) {
            res = f(s, t, rules, costs, index + 1, dp); // nextindex
        }
        for(int i = 0; i < size(rules); i++){
            // brute force
            auto& a = rules[i][0];
            auto& b = rules[i][1];
            int asize = size(a);
            if(size(s) < asize + index) continue;
            bool flag = true; int count = 0;
            for(int j = 0; j < asize; j++){
                if(a[j] == '*')  count ++;
                else if(a[j] != s[j + index]){
                    flag = false; // !flag;
                    break;
                }
            }
            if(flag){
                for(int j = 0; j < size(b); j++){
                    if(b[j] != t[j + index]){
                        flag = false;
                        break;
                    }
                }
                if(!flag) continue;
                // we go on
                long long next = f(s, t, rules, costs, index + asize, dp);
                if(next == LLONG_MAX) continue;
                res = min(res, next + costs[i] + count);
            }
        }
        dp[index] = res;
        return res;
    }
    int minCost(string s, string t, vector<vector<string>>& rules,
                vector<int>& costs) {
        int n = size(s);
        vector<long long> dp(n, -1);
        long long res = f(s, t, rules, costs, 0, dp);
        return res == LLONG_MAX ? -1 : (int)res;
    }
};