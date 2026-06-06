class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> num(size(nums));
        for (int i = 0; i < size(nums); i++) {
            if (i == 0)
                num[i] = i;
            else {
                num[i] = num[i - 1] + nums[i - 1];
            }
        }
        int b;
        for (int i = size(nums) - 1; i >= 0; i--) {
            int a;
            if (i == size(nums) - 1) {
                a = 0;
            } else {
                a = nums[i + 1] + b;
            }
            b = a;
            //cout << a << " ";
            num[i] = num[i] - a;
            num[i] = num[i] > 0 ? num[i] : -num[i]; 
        }
        return num;
    }
};