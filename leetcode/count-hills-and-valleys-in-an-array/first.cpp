class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int l = 0;
        int n = size(nums);
        int i = 1;
        while (i < nums.size() - 1) {
            if (nums[i] == nums[i - 1] || nums[i] == nums[i + 1]) {
                nums.erase(nums.begin() + i);
            } else {
                i++;
            }
        }
        for (int i = 1; i < (size(nums) - 1); i++) {
            if ((nums[i + 1] > nums[i] && nums[i - 1] > nums[i]) ||
                ((nums[i + 1] < nums[i] && nums[i - 1] < nums[i]))) {
                l++;
            }
        }
        return l;
    }
};