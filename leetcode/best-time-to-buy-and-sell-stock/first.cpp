class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> nums = prices ; int max = 0;
        for (int i = nums.size() - 1; i >= 0; i--) {
            int temp = nums[i];
            nums[i] = max;
            if (temp > max)
                max = temp;
        }
        max = 0;
        for (int i = 0; i < nums.size(); i++) {
            if(nums[i]-prices[i]>max){
                max = nums[i]-prices[i];
            }
        }
        return max;
    }
};