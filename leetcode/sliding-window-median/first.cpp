class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        multiset<int> ms(begin(nums), begin(nums) + k);
        auto it = next(ms.begin(), k / 2);
        vector<double> res;
        for (int i = k;; i++) {
            if (k % 2) {
                res.push_back((double)*it);
            } else {
                res.push_back(((double)*it + *prev(it)) / 2.0);
            }
            if (i == n) break;
            ms.insert(nums[i]);
            if (nums[i] < *it) // if inserted before
                it--;
            if (nums[i - k] <= *it) // if the thing to be deleted is also before
                it++;
            ms.erase(ms.lower_bound(nums[i - k]));
        }
        return res;
    }
};