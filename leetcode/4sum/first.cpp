class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, long  long target) {

        sort(nums.begin(), nums.end());
        this->nums = nums;

        for (long  long i = 0; i < nums.size(); i++) {

            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            three(nums[i], target - nums[i], i + 1, nums.size() - 1);
        }

        return res;
    }

    vector<vector<int>> res;
    vector<int> nums;

    void two(long  long first, long  long second, long  long target, long  long l, long  long r) {

        while (l < r) {

            long long sum = (long long)nums[l] + nums[r];

            if (sum == target) {

                res.push_back({(int) first, (int) second, (int) nums[l], (int) nums[r]});

                l++;
                r--;

                while (l < r && nums[l] == nums[l - 1]) {
                    l++;
                }

                while (l < r && nums[r] == nums[r + 1]) {
                    r--;
                }

            } else if (sum < target) {
                l++;
            } else {
                r--;
            }
        }
    }

    void three(long  long first, long  long target, long  long l, long  long r) {
        for (long  long i = l; i <= r; i++) {
            if (i > l && nums[i] == nums[i - 1])
                continue;
            two(first, nums[i], target - nums[i], i + 1, r);
        }
    }

    // vector<vector<long  long>> threeSum(vector<long  long>& nums) {
    //     sort(nums.begin(), nums.end());
    //     this->nums = nums;

    //     for (long  long i = 0; i < nums.size(); i++) {

    //         if (i > 0 && nums[i] == nums[i - 1])
    //             continue;

    //         two(0, nums[i], 0 - nums[i], i + 1, nums.size() - 1);
    //     }

    //     return res;
    // }
};