class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        int n = size(nums), m = n / 2;
        if(n == 1){
            return abs(k - nums[0]);
        } 
        if(n == 2){
            int cost = abs(nums[1] - k);
            if(nums[0] > k) cost += abs(nums[0] - k);
            return cost;
        }
        long long cost = 0;
        bool flag = 0;
        while(m < n && nums[m] < k){
            cost += abs(nums[m] - k);
            m++;
            flag = 1;
        }
        if(flag) return cost;
        while(m >= 0 && nums[m] > k){
            cost += abs(nums[m] - k);
            m--;
        }
        return cost;
    }
};