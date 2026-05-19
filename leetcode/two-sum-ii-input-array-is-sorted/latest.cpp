class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        //if(target > 0) while(nums[r] > target) r--;
        while(l < r){
            if(nums[l] + nums[r] == target) return {l + 1, r + 1};
            else if(nums[l] + nums[r] < target){
                l++;
            }else r--;
        }
        return {-1, -1};
    }
};