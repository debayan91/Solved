class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        int j;
        for (j = 0; j < nums.size(); j++) {
            if (nums[j] != 0) {
                nums[i] = nums[j];
                i++;
            }
        }
        for (j = i; j < nums.size(); j++){
            nums[j] = 0;
        }
    }
};