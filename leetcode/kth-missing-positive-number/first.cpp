class Solution {
public:
    int findKthPositive(vector<int>& nums, int k) {
        int l = 0;
        int h = size(nums) - 1;
        while (l <= h) {
            int m = (l + h) / 2;

            // elements to the left
            int lno = m;

            // total + integers to the left
            int pno = nums[m] - 1;

            // gaps to the left = total before - elements in there
            int gaps = pno - lno;

            // if there are gaps more than k -> go left
            if (gaps >= k) {
                h = m - 1;
            } else {
                l = m + 1;
            }
        }

        return l + k;
    }
};