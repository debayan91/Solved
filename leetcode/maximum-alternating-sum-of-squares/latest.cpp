class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = size(nums);
        for(int& i : nums) i = abs(i);
        sort(begin(nums), end(nums), greater<>());
        long long sum = 0;
        for(int i = 0; i < n; i++){
            if(i < (n + 1) / 2) sum += nums[i] * nums[i];
            else sum -= nums[i] * nums[i];
        }
        return sum;
    }
};