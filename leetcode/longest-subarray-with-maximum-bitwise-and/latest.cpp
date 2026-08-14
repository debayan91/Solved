class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int m = *max_element(begin(nums), end(nums)), i = 0, n = size(nums);
        int mx = 1;
        while(i < n){
            int count = 0;
            if(nums[i] == m){while(i < n && nums[i] == m){
                i++; count++;
            }
            mx = max(mx, count);} else i++;
        }
        return mx;
    }
};