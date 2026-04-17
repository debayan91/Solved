class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int current;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (count == 0) {
                current = nums[i];
            }
            if (nums[i] == current) {
                count++;
            } else {
                count--;
            }
        }
        return current;
    }
};