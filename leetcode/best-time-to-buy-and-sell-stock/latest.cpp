class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int maxprofit = 0;
        int min = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < min){
                min = nums[i];
            }
            int current = nums[i] - min;
            maxprofit = max(maxprofit, current);
        }
        return maxprofit;
    }
};