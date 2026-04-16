class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int max_index;
        int max = -1;
        bool same = true;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= max) {
                max = nums[i];
                max_index = i;
            }
            if(nums[i]!=nums[(i+1)%n]) same = false;
        }
        if(same) return true;
        int min_index = max_index;
        while(nums[min_index]>=nums[max_index]){
            min_index = (min_index+1)%n;
            if(nums[min_index]<nums[max_index]) break;
        }
        for (int i = min_index + 1; i < min_index + n; i++) {
            if(nums[i%n]<nums[(i-1)%n]) return false;
        }
        return true;
    }
};