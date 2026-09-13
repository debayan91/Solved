class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        vector<bool> a(k + 1, false);
        int count = 0, res = 1;
        a[0] = 1;
        while (size(nums)) {
            int b = nums.back();
            if (b <= k && !a[b]) {
                a[b] = 1;
                count++;
                if (count == k)
                    return res;
            }
            nums.pop_back();
            res++;
        }
        return res;
    }
};