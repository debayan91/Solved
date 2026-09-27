class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int n = size(nums), res = 0;
        int mx = 0;
        for (int i = 0; i < n; i++) {
            long long sum = 0;
            set<int> vis;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                int r = ((2 * nums[j]) % k + k) % k;
                vis.insert(r);
                if ((sum % k + k) % k == 0 || vis.count((sum % k + k) % k))
                    res = max(res, j - i + 1);
            }
        }
        return res;
    }
};