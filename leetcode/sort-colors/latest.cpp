class Solution {
public:
    void sortColors(vector<int>& nums) {
        int a = 0;
        int b = nums.size() - 1;
        for (int i = 0; i < b+1; i++){
            if(nums[i] == 0){
                swap(nums[a],nums[i]);
                a++;
            }
            if(nums[i] == 2){
                swap(nums[i],nums[b]);
                b--;
                i--;
            }
        }
    }
};