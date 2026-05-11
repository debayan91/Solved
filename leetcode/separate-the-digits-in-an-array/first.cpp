class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> res;
        for (int i : nums) {
            int digits = floor(log10(i)) + 1;
            int p = pow(10, digits - 1);
            for (int j = 0; j < digits; j++) {
                res.push_back(i / p);
                i %= p;
                p /= 10;
            }
        }
        return res;
    }
};