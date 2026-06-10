class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return false;
        if (n == 1) return nums[0] == target;
        
        int l = 0;
        int h = n - 1;
        
        while (l <= h) {
            int m = l + (h - l) / 2; // Prevents Integer Overflow
            int mid = nums[m];
            
            if (target == mid) return true;
            
            int rightend = nums[h];
            int leftend = nums[l];
            
            // 1. STRIP DUPLICATES FIRST
            if (leftend == mid && mid == rightend) {
                l++;
                h--;
            } 
            // 2. CHECK IF LEFT HALF IS SORTED
            else if (leftend <= mid) {
                if (target >= leftend && target < mid) {
                    h = m - 1;
                } else {
                    l = m + 1;
                }
            } 
            // 3. IF LEFT ISN'T SORTED, RIGHT HALF MUST BE SORTED
            else {
                if (target > mid && target <= rightend) {
                    l = m + 1;
                } else {
                    h = m - 1;
                }
            }
        }
        return false;
    }
};