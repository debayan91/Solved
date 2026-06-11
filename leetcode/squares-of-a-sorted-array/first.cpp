class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res(size(nums));
        int i = 0;
        while (i < size(nums) && nums[i] < 0)
            i++;
        int j = i - 1;
        int k = 0;
        while (j >= 0 && i < size(nums)) {
            if (abs(nums[j]) < nums[i]) {
                res[k++] = nums[j] * nums[j];
                j--;
            } else {
                res[k++] = nums[i] * nums[i];
                i++;
            }
        }
        while (i < size(nums)) {
            res[k++] = nums[i] * nums[i];
            i++;
        }
        while (j >= 0) {
            res[k++] = nums[j] * nums[j];
            j--;
        }
        return res;
    }
};