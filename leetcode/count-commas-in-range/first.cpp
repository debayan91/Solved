class Solution {
public:
    int countCommas(int n) {
        int res = 0;
        for (int i = 1; i <= n; i++) {
            string s = to_string(i);
            if (size(s) > 3) {
                if(size(s) % 3) res += size(s) / 3;
                else res += size(s) / 3 - 1;
            }
        }
        return res;
    }
};