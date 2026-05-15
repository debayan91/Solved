class Solution {
public:
    int bs(vector<int> nums, int l, int h){
        if(l == h) return nums[l];
        if(l + 1 == h) return min(nums[l], nums[h]);
        int mid = (l + h) / 2;
        if(nums[mid] < nums[mid - 1]) return nums[mid]; // direct find 1
        if(nums[mid] > nums[mid + 1]) return nums[mid +1]; // direct find 2
        if(nums[l] < nums[mid]) return bs(nums, mid + 1, h);
        else return bs(nums, l, mid - 1);
    }
    int findMin(vector<int>& nums) {
        if(nums[0] <= nums[nums.size() - 1]) return nums[0]; // unrotated array
        return bs(nums, 0, nums.size() - 1);
    }
};