class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int mx = 0;
        for (int i = 0; i < size(nums); i++) {
            if (nums[i] % 2 || nums[i] > threshold)
                continue;
            int l = i;
            int j;
            int r = l;
            for (j = i; j < size(nums) - 1; j++) {
                if (nums[j + 1] > threshold || nums[j] % 2 == nums[j + 1] % 2) {
                    r = j;
                    break;
                }
                r = j + 1;
            }
            mx = max(mx, r - l + 1);
        }
        return mx;
    }
};