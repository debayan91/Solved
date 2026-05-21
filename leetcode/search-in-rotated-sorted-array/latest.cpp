class Solution {
public:
    int search(vector<int>& nums, int target, int l, int h) {
        if (l > h)
            return -1;

        if (l == h) {
            if (nums[l] == target) {
                return l;
            } else {
                return -1;
            }
        }

        if (l + 1 == h) {
            if (nums[l] == target)
                return l;
            else if (nums[h] == target)
                return h;
            else
                return -1;
        }

        int mid = (l + h) / 2;

        if (nums[mid] == target)
            return mid;


        if (nums[mid] > nums[h]) {
            // the inflection point is to the right
            int low = nums[l];
            int high = nums[mid - 1];
            if (target >= low && target <= high) {
                return search(nums, target, l, mid - 1);
            } else {
                return search(nums, target, mid + 1, h);
            }
        } else {
            int low = nums[mid + 1];
            int high = nums[h];
            if (target >= low && target <= high) {
                return search(nums, target, mid + 1, h);
            } else {
                return search(nums, target, l, mid - 1);
            }
        }
    }
    int search(vector<int>& nums, int target) {
        return search(nums, target, 0, nums.size() - 1);
    }
};