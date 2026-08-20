class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int count = 0;
        unordered_map<int, int> m;
        int start = 0, extra = 0;

        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]]++;

            if (m.size() > k) {
                while (m.size() > k) {
                    m[nums[start]]--;
                    if (m[nums[start]] == 0) m.erase(nums[start]);
                    start++;
                }
                extra = 0;
            }

            if (m.size() == k) {
                while (m[nums[start]] > 1) {
                    m[nums[start]]--;
                    start++;
                    extra++;
                }

                count += extra + 1;
            }
        }

        return count;
    }
};