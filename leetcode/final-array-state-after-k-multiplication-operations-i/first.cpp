class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        for(int i = 0; i < k; i++){
            int k = min_element(begin(nums), end(nums)) - begin(nums);
            nums[k] *= multiplier;
        }
        return nums;
    }
};