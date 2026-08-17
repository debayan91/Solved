class Solution {
public:
    int findMin(vector<int>& nums) {
        //return *min_element(begin(nums), end(nums));
        int l = 0, r = size(nums) - 1;
        while(l <= r){
            int m = l + (r - l) / 2;
            if(nums[m] > nums[r]) l = m + 1;
            else if(nums[m] < nums[r]) r = m;
            else r--;
        }
        return nums[l];
    }
};