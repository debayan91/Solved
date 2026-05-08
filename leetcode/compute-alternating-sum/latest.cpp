class Solution {
public:
    int alternatingSum(vector<int>& nums) {
        for(int i = 1; i < nums.size(); i++){
            if(i % 2 == 0) nums[0] += nums[i];
            else nums[0] -= nums[i];
        }
        return nums[0];
    }
};