class Solution {
public:
    vector<int> replaceElements(vector<int>& nums) {
        int n = nums.size();
        int max = -1;
        for (int i = n - 1; i >= 0; i--) {
            int temp = nums[i];
            nums[i] = max;
            if (temp > max)
                max = temp;
        }
        return nums;
    }
};