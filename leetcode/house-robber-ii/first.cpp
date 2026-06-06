class Solution {
public:
    int r(vector<int>& nums) {
        int a, b, c;
        a = nums[0];
        if (size(nums) == 1)
            return nums[0];
        else
            b = max(nums[0], nums[1]);
        if (nums.size() == 2)
            return b;
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
    int rob(vector<int>& nums) {
        int d, b, c;
        d = nums[0];
        if (size(nums) == 1)
            return nums[0];
        else
            b = max(nums[0], nums[1]);
        if (nums.size() == 2)
            return b;

        vector<int> a(nums.begin() + 1, nums.end());
        int t = r(a); // wo first

        int c1 = r(nums); // using all

        nums.pop_back();
        int c2 = r(nums); // wo last

        if (c1 != c2) {
            return max(t, c2);
        } else {
            return c1;
        }
    }
};