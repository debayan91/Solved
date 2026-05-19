class Solution {
public:
    void two(int element, int l, int r, vector<int>& nums,
             vector<vector<int>>& res) {
        int target = 0 - element;

        while (l < r) {
            if (nums[l] + nums[r] == target) {

                res.push_back({element, nums[l], nums[r]});

                l++;
                r--;

                while (l < r && nums[l] == nums[l - 1]) {
                    l++;
                }

                while (l < r && nums[r] == nums[r + 1]) {
                    r--;
                }

            } else if (nums[l] + nums[r] < target) {
                l++;
            } else
                r--;
        }
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            two(nums[i], i + 1, nums.size() - 1, nums, res);
        }
        return res;
    }
};