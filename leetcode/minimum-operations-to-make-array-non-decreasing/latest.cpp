class Solution {
public:
    long long minOperations(vector<int>& nums) {
        long long sum = 0;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] < nums[i - 1]){
                sum += nums[i - 1] - nums[i];
            }
        }
        return sum;
    }
};