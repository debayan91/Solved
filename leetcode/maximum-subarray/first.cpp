class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int current = 0;
        int mx = INT_MIN;
        for(int i : nums){
            current += i;
            mx = max(current, mx);
            current = current < 0 ? 0 : current;
        }
        return mx;
    }
};