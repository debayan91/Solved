class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxprod = nums[0];
        int mx = maxprod;
        int mn = maxprod;
        // cout << mx << " " << mn << endl;
        for(int i = 1; i < size(nums); i++){
            // when adding anything we can go lower or higher
            // mx is the greatest we can get using current element or prev
            // mn is the lowest we can get using prev and current
            int a = mx;
            int b = mn;
            mx = max(nums[i], max(nums[i] * a, nums[i] * b));
            mn = min(nums[i], min(nums[i] * a, nums[i] * b));
            // cout << mx << " " << mn << endl;
            maxprod = max(maxprod, max(mx, mn));
        }
        return maxprod;
    }
};