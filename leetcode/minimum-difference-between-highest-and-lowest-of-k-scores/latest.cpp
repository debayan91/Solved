class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        int mn = INT_MAX;
        for(int i = 0; i < size(nums) - k + 1; i++){
            int kk = *max_element(begin(nums) + i, begin(nums) + i + k) - *min_element(begin(nums) + i, begin(nums) + i + k);
            mn = min(mn, kk);
        }
        return mn;
    }
};