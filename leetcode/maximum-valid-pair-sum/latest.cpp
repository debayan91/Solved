class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n = size(nums);
        int res = INT_MIN;
        int mx = INT_MIN;
        for(int i = k; i < n; i++){ 
            mx = max(nums[i - k], mx);
            res = max(res, nums[i] + mx);
        }
        return res;
    }
};