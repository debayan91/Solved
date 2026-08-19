class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int n = size(nums), l = 0, r = n - 1, mx = 0, sum = 0;
        for(int i = 0; i < k; i++){
            sum += nums[l++];
        }
        mx = sum; l--;
        for(int i = 0; i < k; i++){
            sum += nums[r--] - nums[l--];
            mx = max(sum, mx);
        }
        return mx;
    }
};