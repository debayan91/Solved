class Solution {
public:
    int minimumCost(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            if((i + 1) % 3) sum += nums[i];
        }
        return sum;
    }
};

