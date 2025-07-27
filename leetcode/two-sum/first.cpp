class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < size(nums); i++) {
            for (int i1 = i + 1; i1 < size(nums); i1++) {
                if ((nums[i1] + nums[i]) == target) {
                    return {i, i1};
                }
            }
        }
                    return {};
    }
};