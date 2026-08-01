class Solution {
public:
    long long minInitialStrength(vector<int>& m, vector<vector<int>>& b) {
        int n = size(m), bn = size(b);
        vector<long long> add(n + 1, 0);
        for(auto& a : b){
            add[a[0]] += a[2];
            add[min(n, a[1] + 1)] -= a[2];
        }
        vector<long long> bb(n, 0);
        long long bonus = 0;
        for(int i = 0; i < n; i++){
            bonus += add[i]; bb[i] += bonus;
        }
        long long carry = 0;
        for(int i = n - 1; i >= 0; i--){
            long long need = m[i] - bb[i];
            carry = (carry == 0LL) ? max(0LL, need) : carry += m[i];
        }
        return carry;
    }
};