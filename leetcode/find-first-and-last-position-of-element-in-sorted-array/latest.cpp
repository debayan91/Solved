class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int a = -1;
        int b = -1;

        if(nums.size() == 0) return {a, b};

        int l = 0;
        int h = nums.size() - 1;
        while (l <= h) {
            int mid = (l + h) / 2;
            if (nums[mid] <= target) {
                l = mid + 1;
            } else {
                h = mid - 1;
            }
            if(nums[mid] == target) b = mid;
        }

        l = 0;
        h = nums.size() - 1;
        while (l <= h) {

            int mid = (l + h) / 2;
            if (nums[mid] >= target) {
                h = mid - 1;
            } else {
                l = mid + 1;
            }
            if(nums[mid] == target) a = mid;
        }

        return {a, b};
    }
};