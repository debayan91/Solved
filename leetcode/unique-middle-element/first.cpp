class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        unordered_map<int, int> m;
        for(int i : nums) m[i]++;
        if(m[nums[size(nums) / 2]] == 1) return true;
        return false;
    }
};