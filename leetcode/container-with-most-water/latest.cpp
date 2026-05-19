class Solution {
public:
    int maxArea(vector<int>& nums) {
        int max = 0;
        int l = 0;
        int r = nums.size() - 1;
        while(l < r){
            int area = nums[l] < nums[r] ? nums[l] * (r - l) : nums[r] * (r - l);
            max = max > area ? max : area;
            
            nums[l] < nums[r] ? l++ : r--;
        }
        return max;
    }
};