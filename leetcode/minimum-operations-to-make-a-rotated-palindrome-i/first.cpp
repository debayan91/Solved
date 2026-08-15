class Solution {
public:
    int minOperations(string s) {
        int n = size(s);
        int mn = INT_MAX;
        string t = s + s;
        for(int i = 0; i < n; i++){
            int cost = i;
            for(int j = 0; j < n / 2; j++){
                char a = t[i + j], b = t[i + n - j - 1];
                int delta = abs(a - b); cost += min(delta, 26 - delta);
            }
            mn = min(mn, cost);
        }
        return mn;
    }
};