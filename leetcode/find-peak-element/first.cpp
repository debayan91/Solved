class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int prev = -1;
        for(int i = 0; i < size(nums); i += 2){
            if(i + 1 < size(nums) && i == 0 && nums[i + 1] < nums[i]) return i;
            else if(i - 1 >= 0 && i == size(nums) - 1 && nums[i - 1] < nums[i]) return i;
            else{
                if(i == 0){
                    prev = nums[i];
                }else{
                    if(i + 1 < size(nums) && i - 1 >= 0 && nums[i] > nums[i - 1] && nums[i] > nums[i + 1]){
                        return i;
                    }
                    if(i - 1 >= 0 && nums[i] < nums[i - 1] && prev < nums[i - 1]){
                        return i - 1;
                    }
                    prev = nums[i];
                }
            }
        }
        return size(nums) - 1;
    }
};