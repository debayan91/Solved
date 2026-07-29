class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int n = size(nums);
        //if(k < n) return max(nums[min(k, n - 1)], *max_element(begin(nums), min(end(nums), begin(nums) + k - 1)));
        if(k < n){
            int after = nums[min(k, n - 1)];
            int inrange = k - 1 <= 0 ? -1 : *max_element(begin(nums), min(end(nums), begin(nums) + k - 1));
            return max(after, inrange);
        }
        if(n == 1 && k % 2) return -1;
        if(k == n){
            return *max_element(begin(nums), end(nums) - 1);
        }
        return *max_element(begin(nums), end(nums));
    }
};