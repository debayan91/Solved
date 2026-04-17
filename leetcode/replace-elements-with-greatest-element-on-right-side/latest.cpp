class Solution {
public:
    vector<int> replaceElements(vector<int>& nums) {
        int max = -1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            int temp = nums[i];
            nums[i] = max;
            if (temp > max)
                max = temp;
        }
        return nums;
    }
};