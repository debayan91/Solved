class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n = size(nums);
        sort(begin(nums), end(nums));
        int a = nums[n - 2] - nums[1];
        int b = nums[n - 1] - nums[2];
        int c = nums[n - 3] - nums[0];
        return min({a, b, c});
    }
};