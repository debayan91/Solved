class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long a = *min_element(begin(nums), end(nums));
        long long b = *max_element(begin(nums), end(nums));
        long long c = k * (b - a);
        return c;
    }
};