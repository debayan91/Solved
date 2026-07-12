class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = size(nums);
        int index = -1;
        for(int i = 0; i < n; i++){
            if(nums[i] % 2 == 0) swap(nums[++index],nums[i]);
        }
        return nums;
    }
};