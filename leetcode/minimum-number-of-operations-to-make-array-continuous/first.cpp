class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        set<int> s(nums.begin(), nums.end());
        vector<int> v(s.begin(), s.end());

        int m = v.size();
        int res = INT_MAX;

        for (int x : v) {
            int cnt = upper_bound(v.begin(), v.end(), x + n - 1) - lower_bound(v.begin(), v.end(), x);

            res = min(res, n - cnt);
        }

        return res;
    }
};