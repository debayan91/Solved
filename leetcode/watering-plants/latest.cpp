class Solution {
public:
    int wateringPlants(vector<int>& nums, int capacity) {
        int n = size(nums);
        long long res = 0, current = capacity;
        for (int i = 0; i < n; i++) {
            res++; // come to current index
            if (current < nums[i]) {
                res += (i) * 2; // visit river
                current = capacity - nums[i];
            } else current -= nums[i];
        }
        return res;
    }
};