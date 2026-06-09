class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(size(nums) == 1) return nums[0];
        for(int i = 0; i < size(nums); i += 2){
            // cout << nums[i] << " " << nums[i + 1] << endl;
            if(i + 1 < size(nums) && nums[i] != nums[i + 1]) return nums[i];
        }
        return nums.back();
    }
};