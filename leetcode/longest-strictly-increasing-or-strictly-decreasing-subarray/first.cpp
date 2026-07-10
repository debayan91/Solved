class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int mx = 1;
        int i = 0;
        while(i < size(nums)){
            if(i < size(nums) - 1 && nums[i] < nums[i + 1]){
                int count = 1;
                while(i < size(nums) - 1 && nums[i] < nums[i + 1]){
                    count++;
                    i++;
                }
                mx = max(mx, count);
            } else i++;
        }
        i = 0;
        while(i < size(nums)){
            if(i < size(nums) - 1 && nums[i] > nums[i + 1]){
                int count = 1;
                while(i < size(nums) - 1 && nums[i] > nums[i + 1]){
                    count++;
                    i++;
                }
                mx = max(mx, count);
            } else i++;
        }
        return mx;
    }
};