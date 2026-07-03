class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        for(int i = 0; i < size(nums) - 1; i++){
            if(nums[i]%2 && nums[i+1]%2){
                return false;
            }
            if(nums[i]%2 == 0 && nums[i+1]%2 == 0){
                return false;
            }
        }
        return true;
    }
};