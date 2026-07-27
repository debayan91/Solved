class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        int a = 0, b = size(nums) - 1;
        int c = 0, d = 0;
        for(int i = 0; i < k; i++){
            c += nums[a++];
            d += nums[b--];
        }
        return abs(c - d);
    }
};