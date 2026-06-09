class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int a = *min_element(begin(nums), end(nums));
        int b = *max_element(begin(nums), end(nums));
        return (long long) k * (b - a);
    }
};