class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = size(nums);
        sort(begin(nums), end(nums));
        if(nums[0] < 0 && nums[1] < 0){
            return max(nums[0] * nums[1] * nums[n - 1], nums[n - 1] * nums[n - 2] * nums[n - 3]);
        } else{
            return nums[n - 1] * nums[n - 2] * nums[n - 3];
        }
    }
};