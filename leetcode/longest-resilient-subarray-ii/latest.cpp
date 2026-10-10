class Solution {
public:
    int resilientSubarray(vector<int>& nums, int k) {
        int n = size(nums);
        auto rem = nums;
        for (int& i : rem)
            i = (i % k + k) % k;

        int i = 0, res = 0;

        while (i < n) {
            int j = i;
            while (j < n && rem[j] == rem[i])
                j++;
            int len = j - i, r = rem[i];

            if (r == 0)
                res = max(res, len);
            else {
                int s = k / gcd(k, r),
                l = ((len - 1) / s) * s + 1;
                
            res = max(res, l);} i = j;
        }
        return res;
    }
};