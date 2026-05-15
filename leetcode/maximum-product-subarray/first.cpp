class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        int mx = res;
        int mn = res;
        for (int i = 1; i < nums.size(); i++) {
            int n_mx = max(nums[i], max(nums[i] * mx, nums[i] * mn));
            int n_mn = min(nums[i], min(nums[i] * mn, nums[i] * mx));
            mx = n_mx;
            mn = n_mn;
            res = max(res, max(mx,mn));
        }
        return res;
    }
};