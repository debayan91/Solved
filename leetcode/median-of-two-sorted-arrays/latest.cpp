class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        vector<int> nums;

        int i = 0;
        int j = 0;

        while (i < m && j < n) {
            if (nums1[i] < nums2[j]) {
                nums.push_back(nums1[i]);
                i++;
            } else {
                nums.push_back(nums2[j]);
                j++;
            }
        }
        while (i < m) {
            nums.push_back(nums1[i]);
            i++;
        }
        while (j < n) {
            nums.push_back(nums2[j]);
            j++;
        }
        int size = nums.size();
        int half = size / 2;
        if (size % 2 == 0) {
            double d = ((double)nums[half] + (double)nums[half - 1]) / 2;
            return d;
        } else {
            return (double)nums[half];
        }
    }
};