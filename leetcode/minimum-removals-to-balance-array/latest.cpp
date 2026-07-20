class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int count = 0;
        int j = 0;
        for (int i = 0; i < nums.size(); i++) {
            while (j < nums.size() && 1LL * nums[i] * k >= nums[j])
                j++;
            count = max(count, j - i);
        }
        return nums.size() - count;
    }
};