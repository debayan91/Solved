class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = size(nums);
        for (int i = 0; i <= n; i++) {
            string s = "";
            for (int j = n - 1; j >= 0; j--) s += ((i >> j) & 1) + '0';
            if (find(nums.begin(), nums.end(), s) == nums.end()) return s;
        }
        return "";
    }
};