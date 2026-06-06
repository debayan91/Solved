class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> arr(nums.size(), 0); // max amount i can steal at i
        arr[0] = nums[0];
        if (size(nums) == 1)
            return nums[0];
        else
            arr[1] = max(nums[0], nums[1]);
        cout << arr[0] << " ";
        bool flag = true;
        for (int i = 2; i < nums.size(); i++) {
            if (flag) {
                if (arr[i - 2] + nums[i] > arr[i - 1]) {
                    // we take the current element
                    arr[i] = nums[i] + arr[i - 2];
                } else {
                    // we do not take the current element
                    arr[i] = arr[i - 1];
                    flag = false;
                }
            } else {
                arr[i] = nums[i] + arr[i - 1];
                flag = true;
            }
            cout << arr[i] << " ";
        }
        return arr.back();
    }
};
