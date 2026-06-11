class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0;
        long curr = 0;
        
        for (int right = 0; right < nums.size(); right++) {
            long target = nums[right];
            curr += target;
            
            if ((right - left + 1) * target - curr > k) { // starts being invalid
                curr -= nums[left];
                left++;
            }
            // if adding the current right helps -> keep increasing
            // else remove the last element that causes - smallest element
        }
        
        return size(nums) - left;
    }
};