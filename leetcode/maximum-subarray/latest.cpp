class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum = INT_MIN;
        int sum = 0;
        for(int num : nums){
            sum += num;
            maxsum = max(maxsum, sum);
            if(sum < 0) sum = 0;
            
        }
        return maxsum;
    }
};