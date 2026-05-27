class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        int max_index = 0;
        int range_end = 0;
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            max_index = max(max_index, i + nums[i]);
            if(i == range_end){
                range_end = max_index;
                count++;
                if(max_index >= nums.size() - 1) return count;
            }
            if(i >= max_index) return -1;
        }
        return -1;
    }
};