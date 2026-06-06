class Solution {
public:
    int rob(vector<int>& nums) {
        int a, b, c;
        a = nums[0];
        if (size(nums) == 1)
            return nums[0];
        else
            b = max(nums[0], nums[1]);
        if(nums.size() == 2) return b;
        bool flag = true;
        for (int i = 2; i < nums.size(); i++) {
            if (flag) {
                if (a + nums[i] > b) {
                    c = nums[i] + a;
                } else {
                    c = b;
                    flag = false;
                }
            } else {
                c = nums[i] + b;
                flag = true;
            }
            a = b;
            b = c;
        }
        return c;
    }
};
