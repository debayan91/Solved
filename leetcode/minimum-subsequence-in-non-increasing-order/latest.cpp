class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        int sum = accumulate(begin(nums), end(nums), 0);
        sort(begin(nums), end(nums));
        vector<int> res;
        int n = size(nums);
        int current = 0;
        for(int i = n - 1; i >= 0; i--){
            current += nums[i];
            res.push_back(nums[i]);
            if(current > sum - current) break;
        }
        return res;
    }
};